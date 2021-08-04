package dao.jdbctemplate;

import dao.beans.Book;
import dao.impl.BookDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@Repository(value="bookDao")
public class BookDAO_JdbcTemplate implements BookDAO {
	@Autowired
	private JdbcTemplate jdbcTemplate;

	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate=jdbcTemplate;
	}

	@Override
	public int addBook(Book book) {
		// TODO Auto-generated method stub
		int rows=0;
		String INSERT_BOOK = "insert into book values(?,?,?,?,?,?)";
		rows = jdbcTemplate.update(INSERT_BOOK, book.getBookName(),
			book.getISBN(), book.getPublication(), book.getPrice(), book.getDescription(), book.getAuthor());
		return rows;
	}

	@Override
	public boolean deleteBook(long ISBN) {
		int rows = 0;
		boolean flag = false;
		String DELETE_BOOK="delete from book where \"ISBN\"=?";
		rows = jdbcTemplate.update(DELETE_BOOK, ISBN);
		if (rows > 0) {
			return true;
		}
		return false;
	}

	@Override
	public int updateBook(long ISBN, int price) {
		int rows = 0;
		String UPDATE_BOOK = "update book set \"price\"=? where \"ISBN\"=?";
		rows = jdbcTemplate.update(UPDATE_BOOK, price, ISBN);
		return rows;
	}

}
