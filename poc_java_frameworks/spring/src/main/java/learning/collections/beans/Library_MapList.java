package learning.collections.beans;

import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;

public class Library_MapList {
    HashMap<String, List<Book>> library;

    public HashMap<String, List<Book>> getLibrary() {
        return library;
    }

    public void setLibrary(HashMap<String, List<Book>> library) {
        this.library = library;
    }

    public void display_books() {
        for(Entry<String,List<Book>> entry : library.entrySet()) {
            System.out.println("Entry:" + entry.getKey());
            for(Book b : entry.getValue()) {
                System.out.println(b);
            }
        }
    }
}
