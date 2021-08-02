package dao.namedtemplate;

import dao.beans.Book;
import dao.impl.BookDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.HashMap;
import java.util.Map;

@Repository(value="bookDao")
public class BookDAO_namedTemplate implements BookDAO {
	@Autowired
	private NamedParameterJdbcTemplate namedParameterJdbcTemplate;

	public void setNamedParameterJdbcTemplate(NamedParameterJdbcTemplate namedParameterJdbcTemplate) {
		this.namedParameterJdbcTemplate = namedParameterJdbcTemplate;
	}

	@Override
	public int addBook(Book book) {
		// TODO Auto-generated method stub
		int rows=0;
		String INSERT_BOOK = "insert into book values(:bookName,:ISBN,:publication,:price,:description,:author)";
		Map<String, Object> params = new HashMap<>();
		params.put("bookName", book.getBookName());
		params.put("ISBN", book.getISBN());
		params.put("publication", book.getPublication());
		params.put("price", book.getPrice());
		params.put("description", book.getDescription());
		params.put("author", book.getAuthor());
		rows = namedParameterJdbcTemplate.update(INSERT_BOOK, params);
		return rows;
	}

	@Override
	public boolean deleteBook(long ISBN) {
		int rows = 0;
		boolean flag = false;
		String DELETE_BOOK="delete from book where \"ISBN\"=:ISBN";
		Map<String, Object> params = new HashMap<>();
		params.put("ISBN", ISBN);
		rows = namedParameterJdbcTemplate.update(DELETE_BOOK, params);
		if (rows > 0) {
			return true;
		}
		return false;
	}

	@Override
	public int updateBook(long ISBN, int price) {
		int rows = 0;
		String UPDATE_BOOK = "update book set \"price\"=:price where \"ISBN\"=:ISBN";
		Map<String, Object> params = new HashMap<>();
		params.put("price", price);
		params.put("ISBN", ISBN);
		rows = namedParameterJdbcTemplate.update(UPDATE_BOOK, params);
		return rows;
	}

}
