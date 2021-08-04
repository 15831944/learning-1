package certification.genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class DuckComparator implements Comparable<DuckComparator> {
    private String name;
    private int weight;
    public DuckComparator(String name, int weight) {
        this.name = name;
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return name;
    }
    public int compareTo(DuckComparator d) {
        return name.compareTo(d.name);
    }
    public static void main(String...args) {
        List<DuckComparator> ducks = new ArrayList<>();
        ducks.add(new DuckComparator("Quack", 10));
        ducks.add(new DuckComparator("Donald", 20));
        Collections.sort(ducks);
        System.out.println(ducks);
        Comparator<DuckComparator> byWeight = (d1, d2) -> d1.getWeight() - d2.getWeight();
/*
        Comparator<DuckComparator> byWeight1 = new Comparator<DuckComparator>() {
            //DOES NOT COMPILE it should be compare
            public int compareTo(DuckComparator d1, DuckComparator d2) {
                return d1.getWeight()—d2.getWeight();
            }
        }; */
        Collections.sort(ducks, byWeight);
        System.out.println(ducks);
    }
}
