package transaction;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import transaction.beans.Book;
import transaction.service.BookService;

public class TemplateTMOperations {
    public static void main(String...args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("transaction_template_jdbctemplate_application_context.xml");
        BookService service = (BookService) context.getBean("bookService");
        // add book
        boolean added = service.addBook(new Book("Java EE 7 Developer Handbook", 97815674L, "PacktPub publication", 332,
                "explore the Java EE7 programming", "Peter pilgrim"));
        if (added) {
            System.out.println("book inserted successfully");
        } else
            System.out.println("SORRY!cannot add book");

        // update the book
        boolean updated = service.updateBook(97815674L, 800);
        if (updated) {
            System.out.println("book updated successfully");
        } else
            System.out.println("SORRY!cannot update book");

        // // delete the book
        boolean deleted = service.deleteBook(97815674L);
        if (deleted) {
            System.out.println("book deleted successfully");
        } else
            System.out.println("SORRY!cannot delete book");

    }
}
