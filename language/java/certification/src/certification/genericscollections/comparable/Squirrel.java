package genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Squirrel {
    private int weight;
    private String species;
    public Squirrel(String theSpecies) {
        if (theSpecies == null) throw new IllegalArgumentException();
        species = theSpecies;
    }
    public int getWeight() { return weight; }
    public void setWeight(int weight) { this.weight = weight; }
    public String getSpecies() { return species; }
    public String toString() {
        return species + " has " + weight + " grams";
    }
    public static void main(String...args) {
        Squirrel s1 = new Squirrel("Chip");
        s1.setWeight(10);
        Squirrel s2 = new Squirrel("Daily");
        s2.setWeight(8);
        Squirrel s3 = new Squirrel("Chip");
        s3.setWeight(8);
        List<Squirrel> list = new ArrayList<>();
        list.add(s1);
        list.add(s2);
        list.add(s3);
        Comparator<Squirrel> comparator = new Comparator<Squirrel>() {
            @Override
            public int compare(Squirrel t1, Squirrel t2) {
                int result = t1.getSpecies().compareTo(t2.getSpecies());
                if (result != 0) return result;
                return t1.getWeight() - t2.getWeight();
            }
        };
        Comparator<Squirrel> comparator1 = new Comparator<Squirrel>() {
            @Override
            public int compare(Squirrel t1, Squirrel t2) {
                Comparator<Squirrel> c= Comparator.comparing(s -> s.getSpecies());
                c = c.thenComparing(s -> s.getWeight());
                return c.compare(t1,t2);
            }
        };
        Collections.sort(list, comparator);
        System.out.println(list);
        list.clear();
        list.add(s1);
        list.add(s2);
        list.add(s3);
        Collections.sort(list, comparator1);
        System.out.println(list);
    }
}
