package dao;

import dao.beans.Book;
import dao.impl.BookDAO;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class MainBookDAOAnnotation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ApplicationContext context=new ClassPathXmlApplicationContext("dao_annotation_application_context.xml");
		BookDAO bookDAO=(BookDAO) context.getBean("bookDao");
		int rows=bookDAO.addBook(new Book("Learning Modular Java Programming", 9781235L,"PacktPub publication",800,"explore the power of Modular programming","T.M.Jog"));
	    if(rows>0)
	    {
	    	System.out.println("book inserted successfully");
	    }
	    else {
			System.out.println("SORRY!cannot add book");
		}
		if (bookDAO.deleteBook(9781235L)) {
			System.out.println("book deleted successfully!");
		} else {
			System.out.println("we could not delete the book");
		}
	}

}
