package learning.collections.beans;

import java.util.HashSet;

public class Library_Set {
    HashSet<Book> books;

    public void display_books() {
        for(Book b : books) {
            System.out.println(b);
        }
    }

    public HashSet<Book> getBooks() {
        return books;
    }

    public void setBooks(HashSet<Book> books) {
        this.books = books;
    }
}
