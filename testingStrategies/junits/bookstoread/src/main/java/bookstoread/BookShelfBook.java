package bookstoread;


import java.time.Year;
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.groupingBy;

public class BookShelfBook {

    private List<Book> books = new ArrayList<>();

    public List<Book> books() {
        return Collections.unmodifiableList(books);
    }

    public void add(final Book...booksToAdd) {
        Arrays.stream(booksToAdd).forEach(books::add);
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("BookShelf{");
        builder.append(books.size() + " books found: ");
        books.stream().forEach(book -> builder.append(book + " "));
        builder.append("}");
        return builder.toString();
    }

    public List<Book> arrange() {
        return arrange(Comparator.naturalOrder());
    }

    public List<Book> arrange(Comparator<Book> criteria) {
        return books.stream().sorted(criteria).collect(Collectors.toList());
    }

    public Map<Year, List<Book>> groupByPublicationYear() {
        return groupBy(book -> Year.of(book.getPublishedOn().getYear()));
    }

    public <K> Map<K,List<Book>> groupBy(Function<Book, K> fx) {
        return books.stream().collect(groupingBy(fx));
    }

    public Progress progress() {
        int booksRead = Long.valueOf(books.stream().filter(Book::isRead).count()).intValue();
        int booksToRead = books.size() - booksRead;
        int percentageCompleted = booksRead * 100 / books.size();
        int percentageToRead = booksToRead * 100 / books.size();
        return new Progress(percentageCompleted, percentageToRead, 0);
    }

    public List<Book> findBooksByTitle(String text) {
        return findBooksByTile(text, b -> true);
    }

    public List<Book> findBooksByTilePredicate(String text, Predicate<Book> filter) {
        List<Book> result = books.stream().filter(a -> a.getTitle().toLowerCase().contains(text)).filter(filter).collect(Collectors.toList());
        return Collections.unmodifiableList(result);
    }

    public List<Book> findBooksByTile(String text, BookFilter filter) {
        List<Book> result = books.stream().filter(a -> a.getTitle().toLowerCase().contains(text)).filter(b -> filter.apply(b)).collect(Collectors.toList());
        return Collections.unmodifiableList(result);
    }
}
