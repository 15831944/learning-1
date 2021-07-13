package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.AuthorRepository;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@DataJpaTest
public class JpaAuthorRepositoryTests {
    private static final String FIRST_NAME = "Mark";
    private static final String LAST_NAME = "Twain";
    @Autowired
    private TestEntityManager manager;

    @Autowired
    private AuthorRepository authorRepository;

    @MockBean
    private BookPubClient client;

    @Test
    public void testAuthorEntityBinding() {
        Long id = manager.persistAndGetId(createAuthor(), Long.class);
        Author author = authorRepository.findById(id).get();
        assertThat(author.getFirstName()).isEqualTo(FIRST_NAME);
        assertThat(author.getLastName()).isEqualTo(LAST_NAME);

    }

    private Author createAuthor() {
        return new Author(FIRST_NAME, LAST_NAME);
    }
}
