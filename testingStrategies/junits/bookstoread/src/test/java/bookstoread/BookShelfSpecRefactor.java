package bookstoread;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@DisplayName("<= BookShelf Specification =>")
public class BookShelfSpecRefactor {

    private BookShelf bookShelf;

    /** Junit5 could have private constructors but it has to be only one
    private BookShelfSpec() {
        // this now could be private
    }
    */
    /** it has builtin resolvers like TestInfoParameterResolver */
    private BookShelfSpecRefactor(TestInfo testInfo) {
        System.out.println("Working on test : " + testInfo.getDisplayName());
    }

    @BeforeEach
    void init() throws Exception {
        bookShelf = new BookShelf();
    }
    /** Junit5 doesn't care about the package access of the classes because it use reflection */
    @Test
    @DisplayName("is empty when no book is added to it")
    protected void shelfEmptyWhenNoBookAdded(TestInfo testInfo) throws  Exception {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        List<String> books = bookShelf.books();
        assertTrue(books.isEmpty(), () -> "BookShelf should be empty.");
    }

    @Test
    @DisplayName("Bookshelf Should Contains Two Books When Two Books are Added")
    protected void bookshelfContainsTwoBooksWhenTwoBooksAdded(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        bookShelf.add("Effective Java", "Code Complete");
        List<String> books = bookShelf.books();
        assertEquals(2, books.size(), () -> "BookShelf should have two books");
    }

    @Test
    @DisplayName("Shelf ToString should print Book Count and Titles")
    protected void shelfToStringShouldPrintBookCountAndTitles(TestInfo testInfo) throws Exception {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        List<String> books = bookShelf.books();
        bookShelf.add("The Phoenix Project");
        bookShelf.add("Java 8 in action");
        String shellStr = bookShelf.toString();
        assertAll(() -> assertTrue(shellStr.contains("The Phoenix Project"), "1st book title missing"),
                () -> assertTrue(shellStr.contains("Java 8 in action"), "2nd book title missing"),
                () -> assertTrue(shellStr.contains("2 books found"), "Book count missing"));
    }

    @Test
    @DisplayName("Books returned is immutable for the client")
    protected void booksReturnedFromBookShelfIsImmutableForClient(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        bookShelf.add("Effective Java", "Code Complete");
        List<String> books = bookShelf.books();
        try {
            books.add("The Mythical Man-Month");
            fail (() -> "Should not be able to add book to books");
        } catch (Exception e) {
            assertTrue(e instanceof UnsupportedOperationException, () -> "Should throw UnsupportedOperationException");
        }
    }

    @Test
    @DisplayName("Shelf Arranged by Book Title")
    protected void bookshelfArrangedByBookTitle(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        bookShelf.add("Effective Java", "Code Complete","The Mythical Man-Month");
        List<String> books = bookShelf.arrange();
        assertEquals(Arrays.asList( "Code Complete", "Effective Java", "The Mythical Man-Month"),
                books, () -> "Books in a bookshelf should be arranged lexicographically by book title");
    }

    @Test
    @DisplayName("Shelf Arranged by Book Title but Remains in Original Order")
    protected void bookshelfArrangedByBookTitleButRemainsInOriginalOrder(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        bookShelf.add("Effective Java", "Code Complete","The Mythical Man-Month");
        List<String> books = bookShelf.arrange();
        assertEquals(Arrays.asList( "Code Complete", "Effective Java", "The Mythical Man-Month"),
                books, () -> "Books in a bookshelf should be arranged lexicographically by book title");
        books = bookShelf.books();
        assertEquals(Arrays.asList("Effective Java", "Code Complete","The Mythical Man-Month"), books, () -> "Books should remain in same input order");
    }
}
