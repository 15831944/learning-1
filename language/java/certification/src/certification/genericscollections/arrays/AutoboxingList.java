package certification.genericscollections.arrays;

import java.util.ArrayList;
import java.util.List;

public class AutoboxingList {
    public static void main(String...args) {
        List<Integer> numbers = new ArrayList<Integer>();
        numbers.add(1);
        //replace with Integer.valueOf
        numbers.add(new Integer(3));
        numbers.add(new Integer(5));
        numbers.remove(1);
        numbers.remove(new Integer(5));
        System.out.println(numbers);
    }
}
