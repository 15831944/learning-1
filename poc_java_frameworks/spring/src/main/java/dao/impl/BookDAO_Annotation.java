package dao.impl;

import dao.beans.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
@Repository(value="bookDao")
public class BookDAO_Annotation implements BookDAO {
	@Autowired
	private DataSource dataSource;

	public void setDataSource(DataSource dataSource) {
		this.dataSource = dataSource;
	}

	@Override
	public int addBook(Book book) {
		// TODO Auto-generated method stub
		int rows=0;
		String INSERT_BOOK="insert into book values(?,?,?,?,?,?)";
		try {
			Connection connection=dataSource.getConnection();
			PreparedStatement ps= connection.prepareStatement(INSERT_BOOK);
			ps.setString(1,book.getBookName());
			ps.setLong(2,book.getISBN());
			ps.setString(3,book.getPublication());
			ps.setInt(4,book.getPrice());
			ps.setString(5,book.getDescription());
			ps.setString(6,book.getAuthor());
			rows=ps.executeUpdate();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return rows;
	}
	@Override
	public boolean deleteBook(long ISBN) {
		int rows = 0;
		String DELETE_BOOK="delete from book where \"ISBN\"=?";
		try {
			Connection connection=dataSource.getConnection();
			PreparedStatement ps= connection.prepareStatement(DELETE_BOOK);
			ps.setLong(1,ISBN);
			rows = ps.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		if(rows > 0) {
			return true;
		} else {
			return false;
		}
	}

}
