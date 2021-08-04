package transaction.service.annotation;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import transaction.beans.Book;
import transaction.dao.BookDAO;
import transaction.service.BookService;

@Service(value = "bookService")
public class BookServiceImpl implements BookService {

    @Autowired
    BookDAO bookDAO;
    @Override
    @Transactional(readOnly = true)
    public Book searchBook(long ISBN) {
        return bookDAO.searchBook(ISBN);
    }

    @Override
    @Transactional
    public boolean addBook(Book book) {
        if(searchBook(book.getISBN()).getISBN() == 98564567l) {
          System.out.println("no book");
          int rows = bookDAO.addBook(book);
          if(rows > 0) {
              return true;
          }
        }
        return false;
    }

    @Override
    @Transactional
    public boolean updateBook(long ISBN, int price) {
        if (searchBook(ISBN).getISBN() == ISBN) {
            int rows = bookDAO.updateBook(ISBN, price);
            if (rows > 0) {
                return true;
            }
        }
        return false;
    }

    @Override
    @Transactional
    public boolean deleteBook(long ISBN) {
        if (searchBook(ISBN).getISBN() != 98564567l) {
            return bookDAO.deleteBook(ISBN);
        }
        return false;
    }
}
