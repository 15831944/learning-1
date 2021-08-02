package certification.genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AnimalIdCompare implements Comparable<AnimalIdCompare>{
    private int id;
    public AnimalIdCompare(int id) {
        this.id = id;
    }
    public boolean equals(Object obj) {
        if(!(obj instanceof AnimalIdCompare)) {
            return false;
        }
        AnimalIdCompare other = (AnimalIdCompare) obj;
        return this.id == other.id;
    }
    public int compareTo(AnimalIdCompare a) {
        return id - a.id;//ascending order ... inverse for descending
    }
    public String toString() {
        return Integer.toString(id);
    }
    public static void main(String...args) {
        AnimalIdCompare a1 = new AnimalIdCompare(5);
        AnimalIdCompare a2 = new AnimalIdCompare(7);
        System.out.println(a1.compareTo(a2)); // -2
        System.out.println(a1.compareTo(a1)); //0
        System.out.println(a2.compareTo(a1)); //2
        List<AnimalIdCompare> list = new ArrayList<>();
        list.add(a2);
        list.add(a1);
        System.out.println(list);
        Collections.sort(list);
        System.out.println(list);
    }
}
