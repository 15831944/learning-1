package com.example.bookpub;

import com.example.bookpub.repository.AuthorRepository;
import com.example.bookpub.repository.BookRepository;
import com.example.bookpub.repository.PublisherRepository;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;
import org.springframework.scheduling.annotation.Scheduled;

import javax.sql.DataSource;
import java.util.Arrays;

@Order(Ordered.LOWEST_PRECEDENCE - 15)
public class StartupRunner implements CommandLineRunner {

    protected final Log logger = LogFactory.getLog(getClass());

    @Autowired
    private BookRepository bookRepository;

    @Override
    public void run(String... args) throws Exception {
/*
    Commented because now it will be populated into the database
        Author author = new Author("Alex", "Antonov");
        author = authorRepository.save(author);
        Publisher publisher = new Publisher("Pack");
        publisher = publisherRepository.save(publisher);
        Book book = new Book("978-1-78528-415-1",
                "Spring Boot Recipes", "The recipes for Sprint",  author, publisher);
        author.setBooks(Arrays.asList(book));
        publisher.setBooks(Arrays.asList(book));
        bookRepository.save(book);
        logger.info("Book" + book);
*/
        logger.info("Number of books: " + bookRepository.count());
    }

    @Scheduled(initialDelay = 1000, fixedRate = 10000)
    public void run() {
        logger.info("Number of books: " + bookRepository.count());
    }

    //populate data
    @Autowired
    private AuthorRepository authorRepository;
    @Autowired
    private PublisherRepository publisherRepository;

}
