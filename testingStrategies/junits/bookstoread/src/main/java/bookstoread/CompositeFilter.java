package bookstoread;

import java.util.ArrayList;
import java.util.List;

public class CompositeFilter implements  BookFilter{
    private List<BookFilter> filters;

    public CompositeFilter() {
        filters = new ArrayList<>();
    }

    @Override
    public boolean apply(Book b) {
        return filters.stream().map(bookFilter -> bookFilter.apply(b)).reduce(true, (b1,b2) -> b1 && b2);
    }

    void addFilter(final BookFilter filter) {
        filters.add(filter);
    }
}
