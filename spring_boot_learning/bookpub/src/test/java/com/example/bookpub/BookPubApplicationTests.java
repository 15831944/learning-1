package com.example.bookpub;

import com.example.bookpub.api.BookPubClient;
import com.example.bookpub.repository.BookRepository;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.boot.web.server.LocalServerPort;
import org.springframework.http.MediaType;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.web.context.WebApplicationContext;

import static org.hamcrest.Matchers.containsString;
import static org.junit.Assert.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;
import static org.springframework.test.web.servlet.setup.MockMvcBuilders.webAppContextSetup;

@RunWith(SpringRunner.class)
@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
public class BookPubApplicationTests {

	@Autowired
	private WebApplicationContext context;

	@Autowired
	private TestRestTemplate restTemplate;


	@Autowired
	private BookRepository repository;

	@MockBean
	private BookPubClient client;

	@LocalServerPort
	private int port;

	private MockMvc mockMvc;

	@Before
	public void setupMockMvc(){
		mockMvc =  webAppContextSetup(context).build();
	}

	@Test
	public void contextLoads() {
		assertEquals(2, repository.count());
	}

	@Test
	public void webappBookIsbnApi() {
		Book book = restTemplate.getForObject("/books/978-1-78528-415-1", Book.class);
		assertNotNull(book);
		assertEquals("Pack", book.getPublisher().getName());
		assertEquals("Alex", book.getAuthor().getFirstName());
	}

	@Test
	public void webappPublisherApi() throws  Exception {
		mockMvc.perform(get("/publishers/2"))
				.andExpect(status().isOk())
				.andExpect(content().contentType(MediaType.parseMediaType("application/hal+json")))
				.andExpect(content().string(containsString("Pack")))
				.andExpect(jsonPath("$.name").value("Pack"));
	}
}
