package dao.hibernate;

import dao.hibernate.beans.Book;
import dao.hibernate.dao.BookDAO;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainBookDAO_HibernateCache_operations {
    public static void main(String...args) {
        ApplicationContext context=new ClassPathXmlApplicationContext("hibernate_cache_application_context.xml");
        BookDAO bookDAO=(BookDAO) context.getBean("bookDAO_sessionFactoryCache");
        int rows=bookDAO.addBook(new Book("Learning Modular Java Programming", 9781234L,"PacktPub publication",800,"explore the power of Modular programming","T.M.Jog"));
        if(rows>0)
        {
            System.out.println("book inserted successfully");
        }
        else {
            System.out.println("SORRY!cannot add book");
            return;
        }
        Book book1 = bookDAO.getBook(9781234L);
        System.out.println("book1 = " + book1.getBookName() + ":" + book1.getAuthor());
        Book book2 = bookDAO.getBook(9781234L);
        System.out.println("book2 = " + book2.getBookName() + ":" + book2.getAuthor());
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
