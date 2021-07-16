package bookstoread;

import org.junit.jupiter.api.*;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mockito;

import java.time.LocalDate;
import java.time.Month;
import java.time.Year;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.Collections.singletonList;
import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

@DisplayName("BookShelfSpecDICacheStore")
@ExtendWith(BooksParameterResolverCacheStore.class)
public class BookShelfSpecDICacheStore {
    private BookShelfBook bookShelf;
    private Book effectiveJava;
    private Book codeComplete;
    private Book mythicalManMonth;
    private Book cleanCode;

    @BeforeEach
    void init(Map<String, Book> books) {
        bookShelf = new BookShelfBook();
        this.effectiveJava=books.get("Effective Java");
        this.codeComplete=books.get("Code Complete");
        this.mythicalManMonth=books.get("The Mythical Man-Month");
        this.cleanCode=books.get("Clean Code");
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
        void bookshelfArrangedByUserProvidedCriteria1(TestInfo testInfo) {
            System.out.println("Working on test case " + testInfo.getDisplayName());
            bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
            Comparator<Book> reversed = Comparator.<Book>naturalOrder().reversed();
            List<Book> books = bookShelf.arrange(reversed);
            assertThat(books).isSortedAccordingTo(reversed);
        }

        @Test
        @DisplayName("book inside bookshelf are grouped by publication year")
        void groupBooksInsideBookShelfByPublicationYear(TestInfo testInfo) {
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
        void groupBooksByUserProvidedCriteria(TestInfo testInfo) {
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

    @Test
    @DisplayName("is 0% completed and 100% to-read when no book is read yet")
    protected void progress100PercentUnread() {
        bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
        Progress progress = bookShelf.progress();
        assertThat(progress.completed()).isEqualTo(0);
        assertThat(progress.toRead()).isEqualTo(100);
    }

    @Test
    @DisplayName("is 33% completed and 60% to-read when 1 book are finished and 2 books not read yet")
    protected void progressWithCompletedAndToReadPercentages() {
        effectiveJava.startedReadingOn(LocalDate.of(2016, Month.JULY, 1));
        effectiveJava.finishedReadingOn(LocalDate.of(2016, Month.JULY, 31));
        cleanCode.startedReadingOn(LocalDate.of(2016, Month.AUGUST, 1));
        bookShelf.add(effectiveJava, codeComplete, mythicalManMonth);
        Progress progress = bookShelf.progress();
        assertThat(progress.completed()).isEqualTo(33);
        assertThat(progress.toRead()).isEqualTo(66);
    }

    @Nested
    @DisplayName("filters")
    class BookShelfSearchSpec {
        @BeforeEach
        void setup() {
            bookShelf.add(codeComplete, effectiveJava, mythicalManMonth, cleanCode);
        }
        @Test
        @DisplayName(" should find books with title containing text")
        void shouldFindBooksWithTitleContainingText() {
            List<Book> books = bookShelf.findBooksByTitle("code");
            assertThat(books.size()).isEqualTo(2);
        }
        @Test
        @DisplayName("book published after a specified year")
        void validateBookPublishedDatePostAskedYear() {
            BookFilter filter = BookPublishedYearFilter.After(2007);
            assertTrue(filter.apply(cleanCode));
            assertFalse(filter.apply(codeComplete));
        }
        @Test
        @DisplayName("Composite criteria is based on multiple filters")
        void shouldFilterOnMultipleCriteria() {
            CompositeFilter compositeFilter = new CompositeFilter();
            compositeFilter.addFilter(b -> false);
            assertFalse(compositeFilter.apply(cleanCode));
        }

        @Test
        @DisplayName("Composite criteria does not invoke after first failure")
        void shouldNotInvokeAfterFirstFailure() {
            CompositeFilter compositeFilter = new CompositeFilter();
            compositeFilter.addFilter(b -> false);
            compositeFilter.addFilter(b -> true);
            assertFalse(compositeFilter.apply(cleanCode));
        }

        @Test
        @DisplayName("Composite criteria invokes all filters")
        void shouldInvokeAllFilters() {
            CompositeFilter compositeFilter = new CompositeFilter();
            compositeFilter.addFilter(b -> true);
            compositeFilter.addFilter(b -> true);
            assertTrue(compositeFilter.apply(cleanCode));
        }
    }
    @Nested
    @DisplayName("mocking")
    class Mocking {
        @BeforeEach
        void setup() {
            bookShelf.add(codeComplete, effectiveJava, mythicalManMonth, cleanCode);
        }

        @Test
        @DisplayName("Composite criteria invokes multiple filters")
        void shouldFilterOnMultipleCriteria() {
            CompositeFilter compositeFilter = new CompositeFilter();
            final Map<Integer, Boolean> invocationMap = new HashMap<>();
            compositeFilter.addFilter(b -> {
                invocationMap.put(1, true);
                return true;
            });
            compositeFilter.apply(cleanCode);
        }
        @Test
        @DisplayName("Composite criteria does not invoke after first failure")
        void shouldNotInvokeAfterFirstFailure() {
            CompositeFilter compositeFilter = new CompositeFilter();
            BookFilter invokedMockedFilter = Mockito.mock(BookFilter.class);
            Mockito.when(invokedMockedFilter.apply(cleanCode)).thenReturn(false);
            compositeFilter.addFilter(invokedMockedFilter);

            BookFilter nonInvokedMockedFilter = Mockito.mock(BookFilter.class);
            Mockito.when(nonInvokedMockedFilter.apply(cleanCode)).thenReturn(true);
            compositeFilter.addFilter(nonInvokedMockedFilter);
            assertFalse(compositeFilter.apply(cleanCode));
            Mockito.verify(invokedMockedFilter).apply(cleanCode);
            Mockito.verifyZeroInteractions(nonInvokedMockedFilter);
        }

        @Test
        @DisplayName("Composite criteria invoke all filters")
        void shouldInvokeAllFilters() {
            CompositeFilter compositeFilter = new CompositeFilter();
            BookFilter firstInvokedMockedFilter = Mockito.mock(BookFilter.class);
            Mockito.when(firstInvokedMockedFilter.apply(cleanCode)).thenReturn(true);
            compositeFilter.addFilter(firstInvokedMockedFilter);

            BookFilter secondInvokedMockedFilter =  Mockito.mock(BookFilter.class);
            Mockito.when(secondInvokedMockedFilter.apply(cleanCode)).thenReturn(true);
            compositeFilter.addFilter(secondInvokedMockedFilter);

            assertTrue(compositeFilter.apply(cleanCode));
            Mockito.verify(firstInvokedMockedFilter).apply(cleanCode);
            Mockito.verify(secondInvokedMockedFilter).apply(cleanCode);
        }
    }
}
