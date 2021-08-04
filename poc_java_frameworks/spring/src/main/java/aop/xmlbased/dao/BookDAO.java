package aop.xmlbased.dao;


import aop.xmlbased.beans.Book;

public interface BookDAO {
	public int addBook(Book book);
	public default int updateBook(long ISBN, int price) {
		return 0;
	}
	public default boolean deleteBook(long ISBN) {
		return true;
	}
}
