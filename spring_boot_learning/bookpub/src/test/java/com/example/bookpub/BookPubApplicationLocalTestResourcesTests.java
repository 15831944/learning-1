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
import org.springframework.jdbc.datasource.init.DatabasePopulatorUtils;
import org.springframework.jdbc.datasource.init.ResourceDatabasePopulator;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.web.context.WebApplicationContext;

import javax.sql.DataSource;

import static org.hamcrest.Matchers.containsString;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;
import static org.springframework.test.web.servlet.setup.MockMvcBuilders.webAppContextSetup;

@RunWith(SpringRunner.class)
@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT)
//those not work yet
//@Transactional
//@Sql(scripts = "classpath:/test-data.sql")
public class BookPubApplicationLocalTestResourcesTests {

	@Autowired
	private WebApplicationContext context;

	@Autowired
	private TestRestTemplate restTemplate;

	@Autowired
	private DataSource ds;

	@Autowired
	private BookRepository repository;

	@LocalServerPort
	private int port;

	@MockBean
	private BookPubClient client;

	private MockMvc mockMvc;
	private static boolean loadDataFixtures = true;

	@Before
	public void setupMockMvc(){
		mockMvc =  webAppContextSetup(context).build();
	}

	@Before
	public void loadDataFixtures() {
		if (loadDataFixtures) {
			ResourceDatabasePopulator populator =
					new ResourceDatabasePopulator(context.getResource("classpath:/test-data.sql"));
			DatabasePopulatorUtils.execute(populator, ds);
			loadDataFixtures = false;
		}
	}
	@Test
	public void contextLoads() {
		assertEquals(3, repository.count());
	}

	@Test
	public void webappBookIsbnApi() {
		Book book = restTemplate.getForObject("/books/978-1-78528-415-1", Book.class);
		assertNotNull(book);
		assertEquals("Pack", book.getPublisher().getName());
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
