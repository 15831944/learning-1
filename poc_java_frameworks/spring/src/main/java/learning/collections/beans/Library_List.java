package learning.collections.beans;

import java.util.List;

public class Library_List {
    private List<Book> books;

    public void displayBooks() {
        for (Book b : books) {
            System.out.println(b);
        }
    }

    public List<Book> getBooks() {
        return books;
    }
    public void setBooks(List<Book> books) {
        this.books = books;
    }
}
