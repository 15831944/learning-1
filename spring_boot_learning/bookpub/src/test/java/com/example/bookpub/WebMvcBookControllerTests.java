package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.AuthorRepository;
import com.example.bookpub.repository.BookRepository;
import com.example.bookpub.repository.PublisherRepository;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.MediaType;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;

import static org.hamcrest.Matchers.containsString;
import static org.mockito.BDDMockito.given;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.jsonPath;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@RunWith(SpringRunner.class)
@WebMvcTest
public class WebMvcBookControllerTests {
    private static final String FIRST_NAME = "William";
    private static final String LAST_NAME = "Shakespeare";
    private static final String PUBLISHER = "Classical Books";
    private static final String ISBN = "978-1-23456-789-1";
    private static final String TITLE = "Romeo and Juliet";
    private static final String DESCRIPTION = "Romeo and Juliet";

    @Autowired
    private MockMvc mockMvc;

    @MockBean
    private BookPubClient client;

    @MockBean
    private BookRepository bookRepository;

    //need repository for the StartupRunner
    @MockBean
    private AuthorRepository authorRepository;

    @MockBean
    private PublisherRepository publisherRepository;

    @Test
    public void webappBookApi() throws  Exception {
        given(bookRepository.findBookByIsbn(ISBN)).willReturn(new Book(ISBN, TITLE, DESCRIPTION,
                new Author(FIRST_NAME, LAST_NAME), new Publisher(PUBLISHER)));
        mockMvc.perform(get("/books/"+ISBN))
                .andExpect(status().isOk())
                .andExpect(content().contentType(MediaType.parseMediaType("application/json")))
                .andExpect(content().string(containsString(TITLE)))
                .andExpect(jsonPath("$.isbn").value(ISBN));
    }
}
