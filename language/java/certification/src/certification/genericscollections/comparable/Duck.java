package genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Duck implements Comparable<Duck> {
    private String name;
    private int weight;
    public Duck(String name) {
        this.name = name;
    }
    public String toString() {
        return name;
    }
    public int getWeight() {
        return weight;
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
    public String getName() {
        return name;
    }
    public int compareTo(Duck d) {
        return name.compareTo(d.name);
    }
    public static void main(String...args) {
        List<Duck> ducks = new ArrayList<>();
        ducks.add(new Duck("Quack"));
        ducks.add(new Duck("Donald"));
        Collections.sort(ducks);
        System.out.println(ducks);
    }
}
