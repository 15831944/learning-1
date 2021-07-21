package genericscollections.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class DuckHelper {
    public static int compareByWeight(Duck d1, Duck d2) {
        return d1.getWeight() - d2.getWeight();
    }

    public static int compareByName(Duck d1, Duck d2) {
        return d1.getName().compareTo(d2.getName());
    }
    public static void main(String...args) {
        List<Duck> ducks = new ArrayList<>();
        Duck d = new Duck("Quack");
        d.setWeight(10);
        ducks.add(d);
        d = new Duck("Donald");
        d.setWeight(20);
        ducks.add(d);
        Comparator<Duck> byWeight = (d1, d2) -> DuckHelper.compareByWeight(d1, d2);
        Collections.sort(ducks, byWeight);
        System.out.println(ducks);
        Comparator<Duck> byName = DuckHelper::compareByName;
        Collections.sort(ducks, byName);
        System.out.println(ducks);
    }
}