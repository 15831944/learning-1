package bookstoread;

import org.junit.jupiter.api.*;

import java.time.LocalDate;
import java.time.Month;
import java.time.Year;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import static java.util.Collections.singletonList;
import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

@DisplayName("<= BookShelf Specification =>")
public class BookShelfBookSpecNested {

    private BookShelfBook bookShelf;
    private Book effectiveJava;
    private Book codeComplete;
    private Book mythicalManMonth;
    private Book cleanCode;

    /** Junit5 could have private constructors but it has to be only one
    private BookShelfSpec() {
        // this now could be private
    }
    */
    /** it has builtin resolvers like TestInfoParameterResolver */
    private BookShelfBookSpecNested(TestInfo testInfo) {
        System.out.println("Working on test : " + testInfo.getDisplayName());
    }

    @BeforeEach
    void init() throws Exception {
        bookShelf = new BookShelfBook();
        effectiveJava = new Book("Effective Java", "Joshua Bloch", LocalDate.of(2008, Month.MAY, 8));
        codeComplete = new Book("Code Complete", "Steve McConnel", LocalDate.of(2004, Month.JUNE, 9));
        mythicalManMonth = new Book("The Mythical Man-Month", "Frederick Phillips Brooks", LocalDate.of(1975, Month.JANUARY, 1));
        cleanCode = new Book("Clean Code", "Robert C. Martin", LocalDate.of(2008, Month.AUGUST, 1));
    }

    @Nested
    @DisplayName("is empty")
    class isEmpty {
        @Test
        @DisplayName("is empty when no book is added to it")
        protected void shelfEmptyWhenNoBookAdded(TestInfo testInfo) throws  Exception {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            List<Book> books = bookShelf.books();
            assertTrue(books.isEmpty(), () -> "BookShelf should be empty.");
        }
        @Test
        @DisplayName("is empty when no book add is called with no books")
        protected void emptyShelfWhenAddisCalledWitoutBooks(TestInfo testInfo) throws  Exception {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add();
            List<Book> books = bookShelf.books();
            assertTrue(books.isEmpty(), () -> "BookShelf should be empty.");
        }
    }
    @Nested
    @DisplayName("after adding books")
    class BooksAreAdded {
        @Test
        @DisplayName("Bookshelf Should Contains Two Books When Two Books are Added")
        protected void bookshelfContainsTwoBooksWhenTwoBooksAdded(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete);
            List<Book> books = bookShelf.books();
            assertEquals(2, books.size(), () -> "BookShelf should have two books");
        }

        @Test
        @DisplayName("Books returned is immutable for the client")
        protected void booksReturnedFromBookShelfIsImmutableForClient(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete);
            List<Book> books = bookShelf.books();
            try {
                books.add(mythicalManMonth);
                fail(() -> "Should not be able to add book to books");
            } catch (Exception e) {
                assertTrue(e instanceof UnsupportedOperationException, () -> "Should throw UnsupportedOperationException");
            }
        }
    }

    @Nested
    @DisplayName("Shelf arrangements")
    class ShelfArrangements {
        @Test
        @DisplayName("Shelf Arranged by Book Title")
        protected void bookshelfArrangedByBookTitle(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
            List<Book> books = bookShelf.arrange();
            assertEquals(Arrays.asList( "Code Complete", "Effective Java", "The Mythical Man-Month"),
                    books.stream().map(b -> b.getTitle()).collect(Collectors.toList()),
                    () -> "Books in a bookshelf should be arranged lexicographically by book title");
        }
        @Test
        @DisplayName("Shelf Arranged by Book Title but Remains in Original Order")
        protected void bookshelfArrangedByBookTitleButRemainsInOriginalOrder(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
            List<Book> books = bookShelf.arrange();
            assertEquals(Arrays.asList("Code Complete", "Effective Java", "The Mythical Man-Month"),
                    books.stream().map(b -> b.getTitle()).collect(Collectors.toList()),
                    () -> "Books in a bookshelf should be arranged lexicographically by book title");
            books = bookShelf.books();
            assertEquals(Arrays.asList("Effective Java", "Code Complete", "The Mythical Man-Month"),
                    books.stream().map(b -> b.getTitle()).collect(Collectors.toList()), () -> "Books should remain in same input order");
        }

        @Test
        @DisplayName("Shelf Arranged by User Provided Criteria")
        protected void bookshelfArrangedByUserProvidedCriteria(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
            List<Book> books = bookShelf.arrange(Comparator.<Book>naturalOrder().reversed());
            assertEquals(Arrays.asList("The Mythical Man-Month", "Effective Java", "Code Complete"),
                    books.stream().map(b -> b.getTitle()).collect(Collectors.toList()),
                    () -> "Books in a bookshelf should be arranged in reversed lexicographically by book title");
            books = bookShelf.books();
            assertEquals(Arrays.asList("Effective Java", "Code Complete", "The Mythical Man-Month"),
                    books.stream().map(b -> b.getTitle()).collect(Collectors.toList()), () -> "Books should remain in same input order");
        }

        @Test
        @DisplayName("Shelf Arranged by User Provided Criteria using assertj")
        protected void bookshelfArrangedByUserProvidedCriteria1(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
            Comparator<Book> reversed = Comparator.<Book>naturalOrder().reversed();
            List<Book> books = bookShelf.arrange(reversed);
            assertThat(books).isSortedAccordingTo(reversed);
        }

        @Test
        @DisplayName("book inside bookshelf are grouped by publication year")
        protected void groupBooksInsideBookShelfByPublicationYear(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth, cleanCode);
            Map<Year, List<Book>> booksByPublicationYear = bookShelf.groupByPublicationYear();
            assertThat(booksByPublicationYear)
                    .containsKey(Year.of(2008))
                    .containsValues(Arrays.asList(effectiveJava, cleanCode));
            assertThat(booksByPublicationYear)
                    .containsKey(Year.of(2004))
                    .containsValues(singletonList(codeComplete));
            assertThat(booksByPublicationYear)
                    .containsKey(Year.of(1975))
                    .containsValues(singletonList(mythicalManMonth));
        }

        @Test
        @DisplayName("books inside bookshelf are grouped according to user provided criteria (group by author)")
        protected void groupBooksByUserProvidedCriteria(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth, cleanCode);
            Map<String, List<Book>> booksByAuthor = bookShelf.groupBy(Book::getAuthor);
            assertThat(booksByAuthor).containsKey("Joshua Bloch")
                    .containsValues(singletonList(effectiveJava));
            assertThat(booksByAuthor).containsKey("Steve McConnel")
                    .containsValues(singletonList(codeComplete));
            assertThat(booksByAuthor).containsKey("Frederick Phillips Brooks")
                    .containsValues(singletonList(mythicalManMonth));
            assertThat(booksByAuthor).containsKey("Robert C. Martin")
                    .containsValues(singletonList(cleanCode));
        }
    }
}
