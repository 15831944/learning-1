package bookstoread;

import org.junit.jupiter.api.*;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class BookShelfDBSpec extends DBConnectionPool {

    private BookShelfDBSpec(TestInfo testInfo) {
        System.out.println("Working on test " + testInfo.getDisplayName());
    }
    @BeforeEach
    void initializeShelfWithDatabase() {
        System.out.println("Initialize the Shelf in Database");
    }

    @Test
    @DisplayName("Just a display test")
    void justDisplayTest(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
    }
    /** Junit5 doesn't care about the package access of the classes because it use reflection */
    @Test
    @DisplayName("is empty when no book is added to it")
    protected void shelfEmptyWhenNoBookAdded(TestInfo testInfo) throws  Exception {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        BookShelf shelf = new BookShelf();
        List<String> books = shelf.books();
        assertTrue(books.isEmpty(), () -> "BookShelf should be empty.");
    }

    @AfterEach
    void deleteDataFromShelf() {
        System.out.println("Delete all data from Shelf in Database");
    }
}
