package bookstoread;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@DisplayName("<= BookShelf Specification =>")
public class BookShelfSpec {

    /** Junit5 could have private constructors but it has to be only one
    private BookShelfSpec() {
        // this now could be private
    }
    */
    /** it has builtin resolvers like TestInfoParameterResolver */
    private BookShelfSpec(TestInfo testInfo) {
        System.out.println("Working on test : " + testInfo.getDisplayName());
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

    @Test
    @DisplayName("Bookshelf Should Contains Two Books When Two Books are Added")
    protected void bookshelfContainsTwoBooksWhenTwoBooksAdded(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        BookShelf bookShelf = new BookShelf();
/*
        bookShelf.add("Effective Java");
        bookShelf.add("Code Complete");
 */
        bookShelf.add("Effective Java", "Code Complete");
        List<String> books = bookShelf.books();
        assertEquals(2, books.size(), () -> "BookShelf should have two books");
    }

    @Test
    @DisplayName("Shelf ToString should print Book Count and Titles")
    protected void shelfToStringShouldPrintBookCountAndTitles(TestInfo testInfo) throws Exception {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        BookShelf shelf = new BookShelf();
        List<String> books = shelf.books();
        shelf.add("The Phoenix Project");
        shelf.add("Java 8 in action");
        String shellStr = shelf.toString();
        //old version
        /*
        assertTrue(shellStr.contains("The Phoenix Project"), "1st book title missing");
        assertTrue(shellStr.contains("Java 8 in action"), "2nd book title missing");
        assertTrue(shellStr.contains("2 books found"), "Book count missing");
         */
        assertAll(() -> assertTrue(shellStr.contains("The Phoenix Project"), "1st book title missing"),
                () -> assertTrue(shellStr.contains("Java 8 in action"), "2nd book title missing"),
                () -> assertTrue(shellStr.contains("2 books found"), "Book count missing"));
    }

    @Test
    @DisplayName("Books returned is immutable for the client")
    protected void booksReturnedFromBookShelfIsImmutableForClient(TestInfo testInfo) {
        System.out.println("Working on test case " + testInfo.getDisplayName());
        BookShelf bookShelf = new BookShelf();
        bookShelf.add("Effective Java", "Code Complete");
        List<String> books = bookShelf.books();
        try {
            books.add("The Mythical Man-Moth");
            fail (() -> "Should not be able to add book to books");
        } catch (Exception e) {
            assertTrue(e instanceof UnsupportedOperationException, () -> "Should throw UnsupportedOperationException");
        }
    }
}
