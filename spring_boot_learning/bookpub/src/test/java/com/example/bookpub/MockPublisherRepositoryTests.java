package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.PublisherRepository;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.BDDMockito.given;
import static org.mockito.Mockito.reset;

@RunWith(SpringRunner.class)
@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.NONE)
public class MockPublisherRepositoryTests {
    @MockBean
    private PublisherRepository repository;

    @MockBean
    private BookPubClient client;

    @Before
    public void setupPublisherRepositoryMock() {
        given(repository.count()).willReturn(5L);
    }

    @Test
    public void publisherExists() {
        assertThat(repository.count()).isEqualTo(5L);
    }

    @After
    public void resetPublisherRepositoryMock() {
        reset(repository);
    }
}
