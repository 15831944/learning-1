package transaction.service;

import transaction.beans.Book;

public interface BookService {
    public Book searchBook(long ISBN);
    public boolean addBook(Book book);
    public boolean updateBook(long ISBN, int price);
    public boolean deleteBook(long ISBN);
}
