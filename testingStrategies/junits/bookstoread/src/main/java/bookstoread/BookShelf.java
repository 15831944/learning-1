package bookstoread;

import java.util.*;
import java.util.stream.Collectors;

public class BookShelf {

    private List<String> books = new ArrayList<>();

    public List<String> books() {
        return Collections.unmodifiableList(books);
    }

    public void add(final String book) {
        books.add(book);
    }

    public void add(final String... booksToAdd) {
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

    public List<String> arrange() {
        //books.sort(Comparator.naturalOrder());
        return books.stream().sorted().collect(Collectors.toList());
    }
}
