package learning.collections.beans;

import java.util.HashMap;
import java.util.Map.Entry;

public class Library_Map {
    HashMap<String,Book> books;

    public HashMap<String, Book> getBooks() {
        return books;
    }

    public void setBooks(HashMap<String, Book> books) {
        this.books = books;
    }
    public void display_books() {
        for(Entry<String,Book> entry : books.entrySet()) {
            System.out.println(entry);
        }
    }
}
