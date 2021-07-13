package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.PublisherRepository;
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
public class JpaPublisherRepositoryTests {
    private static final String PACK = "Pack";
    @Autowired
    private TestEntityManager manager;

    @Autowired
    private PublisherRepository publisherRepository;

    @MockBean
    private BookPubClient client;

    @Test
    public void testPublisherRepositoryBinding() {
        Long id = manager.persistAndGetId(createPublisher(), Long.class);
        Publisher publisher = publisherRepository.findById(id).get();
        assertThat(publisher.getName()).isEqualTo(PACK);
    }

    private Publisher createPublisher() {
        return new Publisher(PACK);
    }
}
