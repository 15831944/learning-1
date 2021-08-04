package dao.hibernate.dao;

import dao.hibernate.beans.Book;

public interface BookDAO {
	public int addBook(Book book);
	public default int updateBook(long ISBN, int price) {
		return 0;
	}
	public default boolean deleteBook(long ISBN) {
		return true;
	}
	public default Book getBook(long ISBN) {
		return new Book("Learning Modular Java Programming", 9781234L,"PacktPub publication",800,"explore the power of Modular programming","T.M.Jog");
	}
}
