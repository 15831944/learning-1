package genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

//java.util.Comparable does not exist in java 13
public class AnimalIdCompareLegacy implements Comparable{
    private int id;
    public AnimalIdCompareLegacy(int id) {
        this.id = id;
    }
    public int compareTo(Object a) {
        return id - ((AnimalIdCompareLegacy)a).id;//ascending order ... inverse for descending
    }
    public String toString() {
        return Integer.toString(id);
    }
    public static void main(String...args) {
        AnimalIdCompareLegacy a1 = new AnimalIdCompareLegacy(5);
        AnimalIdCompareLegacy a2 = new AnimalIdCompareLegacy(7);
        System.out.println(a1.compareTo(a2)); // -2
        System.out.println(a1.compareTo(a1)); //0
        System.out.println(a2.compareTo(a1)); //2
        List<AnimalIdCompareLegacy> list = new ArrayList<>();
        list.add(a2);
        list.add(a1);
        System.out.println(list);
        Collections.sort(list);
        System.out.println(list);
    }
}
