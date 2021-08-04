package transaction.service.platform;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.TransactionDefinition;
import org.springframework.transaction.TransactionStatus;
import org.springframework.transaction.support.DefaultTransactionDefinition;
import transaction.beans.Book;
import transaction.dao.BookDAO;
import transaction.service.BookService;

@Service(value="bookService")
public class BookServiceImpl implements BookService {
    @Autowired
    PlatformTransactionManager transactionManager;

    @Autowired
    BookDAO bookDAO;

    @Override
    public Book searchBook(long ISBN) {
        TransactionDefinition definition = new DefaultTransactionDefinition();
        TransactionStatus transactionStatus = transactionManager.getTransaction(definition);
        ((DefaultTransactionDefinition)definition).setReadOnly(true);
        Book book = bookDAO.searchBook(ISBN);
        return book;
    }

    @Override
    public boolean addBook(Book book) {
        TransactionDefinition definition = new DefaultTransactionDefinition();
        TransactionStatus transactionStatus = transactionManager.getTransaction(definition);
        if(searchBook(book.getISBN()).getISBN( ) == 98564567l) {
            System.out.println("no book");
            int rows = bookDAO.addBook(book);
            if (rows > 0) {
                transactionManager.commit(transactionStatus);
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean updateBook(long ISBN, int price) {
        TransactionDefinition transactionDefinition = new DefaultTransactionDefinition();
        TransactionStatus transactionStatus = transactionManager.getTransaction(transactionDefinition);
        if(searchBook(ISBN).getISBN() == ISBN) {
            int rows = bookDAO.updateBook(ISBN, price);
            if(rows > 0) {
                transactionManager.commit(transactionStatus);
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean deleteBook(long ISBN) {
        TransactionDefinition defintion = new DefaultTransactionDefinition();
        TransactionStatus transactionStatus = transactionManager.getTransaction(defintion);
        if(searchBook(ISBN).getISBN() != 98564567l) {
            boolean deleted = bookDAO.deleteBook(ISBN);
            if (deleted) {
                transactionManager.commit(transactionStatus);
                return true;
            }
        }
        return false;
    }
}
