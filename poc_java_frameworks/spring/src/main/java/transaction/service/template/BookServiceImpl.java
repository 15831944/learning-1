package transaction.service.template;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.TransactionStatus;
import org.springframework.transaction.support.TransactionCallback;
import org.springframework.transaction.support.TransactionTemplate;
import transaction.beans.Book;
import transaction.dao.BookDAO;
import transaction.service.BookService;

@Service(value="bookService")
public class BookServiceImpl implements BookService {
    @Autowired
    TransactionTemplate transactionTemplate;

    @Autowired
    BookDAO bookDAO;

    @Override
    public Book searchBook(long ISBN) {
        transactionTemplate.setReadOnly(true);
        return transactionTemplate.execute(new TransactionCallback<Book>() {
            @Override
            public Book doInTransaction(TransactionStatus transactionStatus) {
                return bookDAO.searchBook(ISBN);
/*
    not allowed to modify the read-only transaction.
                Book book = new Book();
                book.setISBN(ISBN);
                bookDAO.addBook(book);
                return book;
 */           }
        });
    }

    @Override
    public boolean addBook(Book book) {
        if(searchBook(book.getISBN()).getISBN( ) == 98564567l) {
            System.out.println("no book");
            transactionTemplate.setReadOnly(false);
            return transactionTemplate.execute(new TransactionCallback<Boolean>() {
                @Override
                public Boolean doInTransaction(TransactionStatus transactionStatus) {
                    try {
                        int rows = bookDAO.addBook(book);
                        if (rows > 0) {
                            return true;
                        }
                    } catch (Exception ex) {
                        transactionStatus.setRollbackOnly();
                    }
                    return false;
                }
            });
        }
        return false;
    }

    @Override
    public boolean updateBook(long ISBN, int price) {
        if(searchBook(ISBN).getISBN() == ISBN) {
            transactionTemplate.setReadOnly(false);
            return transactionTemplate.execute(new TransactionCallback<Boolean>() {
                @Override
                public Boolean doInTransaction(TransactionStatus transactionStatus) {
                    try {
                        int rows = bookDAO.updateBook(ISBN, price);
                        if (rows > 0) {
                            return true;
                        }
                    } catch (Exception ex) {
                        transactionStatus.setRollbackOnly();
                    }
                    return false;
                }
            });
        }
        return false;
    }

    @Override
    public boolean deleteBook(long ISBN) {
        if(searchBook(ISBN).getISBN() != 98564567l) {
            transactionTemplate.setReadOnly(false);
            return transactionTemplate.execute(new TransactionCallback<Boolean>() {
                @Override
                public Boolean doInTransaction(TransactionStatus transactionStatus) {
                    try {
                        return bookDAO.deleteBook(ISBN);
                    } catch (Exception ex) {
                        transactionStatus.setRollbackOnly();
                    }
                    return false;
                }
            });
        }
        return false;
    }
}
