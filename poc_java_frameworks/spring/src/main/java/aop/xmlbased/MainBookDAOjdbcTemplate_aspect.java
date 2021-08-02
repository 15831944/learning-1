package aop.xmlbased;

import aop.xmlbased.beans.Book;
import aop.xmlbased.dao.BookDAO;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class MainBookDAOjdbcTemplate_aspect {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext context=new ClassPathXmlApplicationContext("aop_dao_jdbctemplate_application_context.xml");
		BookDAO bookDAO=(BookDAO) context.getBean("bookDao");
		int rows=bookDAO.addBook(new Book("Learning Modular Java Programming", 9781234L,"PacktPub publication",800,"explore the power of Modular programming","T.M.Jog"));
	    if(rows>0)
	    {
	    	System.out.println("book inserted successfully");
	    	try {
				rows = bookDAO.addBook(new Book("Learning Modular Java Programming", 9781234L, "PacktPub publication", 800, "explore the power of Modular programming", "T.M.Jog"));
			} catch (Throwable e) {
			}
	    }
	    else {
			System.out.println("SORRY!cannot add book");
			return;
		}
	    rows =bookDAO.updateBook(9781234L, 432);
	    if(rows > 0) {
	    	System.out.println("book update successfully");
		} else {
	    	System.out.println("SORRY! cannot update book");
		}
	    boolean deleted = bookDAO.deleteBook(9781234L);
	    if (deleted) {
	    	System.out.println("book deleted successfully");
		} else {
	    	System.out.println("SORRY! cannot delete book");
		}
	}

}
