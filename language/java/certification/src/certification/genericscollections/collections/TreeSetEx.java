package genericscollections.collections;

import java.util.NavigableSet;
import java.util.TreeSet;

public class TreeSetEx {
    public static void main(String...args) {
        NavigableSet<Integer> set = new TreeSet<>();
        for (int i = 0; i <= 20; i++)
            set.add(i);
        System.out.println(set.lower(10)); //9
        System.out.println(set.floor(10));//10
        System.out.println(set.ceiling(20));//20
        System.out.println(set.higher(20)); //null
    }
}
