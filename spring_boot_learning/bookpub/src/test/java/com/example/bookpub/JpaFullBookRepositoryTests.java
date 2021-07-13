package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.AuthorRepository;
import com.example.bookpub.repository.BookRepository;
import com.example.bookpub.repository.PublisherRepository;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.Arrays;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.Assert.assertNotNull;

@RunWith(SpringRunner.class)
@DataJpaTest
public class JpaFullBookRepositoryTests {
    private static final String FIRST_NAME = "William";
    private static final String LAST_NAME = "Shakespeare";
    private static final String PUBLISHER = "Classical Books";
    private static final String ISBN = "978-1-23456-789-1";
    private static final String TITLE = "Romeo and Juliet";
    private static final String DESCRIPTION = "Romeo and Juliet";

    @Autowired
    private TestEntityManager manager;

    @Autowired
    private AuthorRepository authorRepository;

    @Autowired
    private PublisherRepository publisherRepository;

    @Autowired
    private BookRepository bookRepository;

    @MockBean
    private BookPubClient client;

    @Test
    public void testJpaFullRepositories() {
        Author author = new Author(FIRST_NAME, LAST_NAME);
        Publisher publisher = new Publisher(PUBLISHER);
        Book book = new Book(ISBN, TITLE, DESCRIPTION, author, publisher);
        publisher.setBooks(Arrays.asList(book));
        author.setBooks(Arrays.asList(book));
        Long authorId = manager.persistAndGetId(author, Long.class);
        Long publisherId = manager.persistAndGetId(publisher, Long.class);
        Long bookId = manager.persistAndGetId(book, Long.class);
        //validate author
        author = authorRepository.findById(authorId).get();
        assertThat(author.getFirstName()).isEqualTo(FIRST_NAME);
        assertThat(author.getLastName()).isEqualTo(LAST_NAME);
        assertNotNull(author.getBooks().get(0));
        assertThat(author.getBooks().get(0).getIsbn()).isEqualTo(ISBN);
        //validate publisher
        publisher = publisherRepository.findById(publisherId).get();
        assertThat(publisher.getName()).isEqualTo(PUBLISHER);
        book = bookRepository.findById(bookId).get();
        assertThat(book.getIsbn()).isEqualTo(ISBN);
        assertNotNull(book.getAuthor());
        assertThat(book.getAuthor().getFirstName()).isEqualTo(FIRST_NAME);
        assertNotNull(book.getPublisher());
        assertThat(book.getPublisher().getName()).isEqualTo(PUBLISHER);
    }
}
