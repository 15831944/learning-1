package transaction.dao;

import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.RowMapper;
import transaction.beans.Book;
import org.apache.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.sql.ResultSet;
import java.sql.SQLException;

@Repository(value="bookDao")
public class BookDAO_JdbcTemplate implements BookDAO {
	@Autowired
	private JdbcTemplate jdbcTemplate;

	Logger logger = Logger.getLogger(BookDAO_JdbcTemplate.class);
	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate=jdbcTemplate;
	}

	@Override
	public int addBook(Book book) {
		// TODO Auto-generated method stub
		int rows=0;
		String INSERT_BOOK = "insert into book values(?,?,?,?,?,?)";
		logger.info("adding the book in table");
		rows = jdbcTemplate.update(INSERT_BOOK, book.getBookName(),
			book.getISBN(), book.getPublication(), book.getPrice(), book.getDescription(), book.getAuthor());
		logger.info("book added in the table successfully " + rows + " affected");
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

	@Override
	public Book searchBook(long ISBN) {
		String SEARCH_BOOK = "select * from book where \"ISBN\"=?";
		Book book_searched = null;
		try {
			book_searched = jdbcTemplate.queryForObject(SEARCH_BOOK, new Object[] {ISBN},
				new RowMapper<Book>() {
					@Override
					public Book mapRow(ResultSet set, int rowNur) throws SQLException {
						Book book = new Book();
						book.setBookName(set.getString("bookName"));
						book.setAuthor(set.getString("author"));
						book.setDescription(set.getString("description"));
						book.setISBN(set.getLong("ISBN"));
						book.setPrice(set.getInt("price"));
						book.setPublication(set.getString("publication"));
						return book;
					}
				});
			return book_searched;
		} catch (EmptyResultDataAccessException ex) {
			return new Book();
		}
	}
}
