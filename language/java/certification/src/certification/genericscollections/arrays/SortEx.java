package certification.genericscollections.arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SortEx {
    public static void main(String...args) {
        int[] numbers = {6,9,1,8};
        Arrays.sort(numbers);
        System.out.println(Arrays.binarySearch(numbers, 6));
        System.out.println(Arrays.binarySearch(numbers, 3));
        List<Integer> ints = new ArrayList<>();
        ints.add(6);
        ints.add(9);
        ints.add(1);
        ints.add(8);
        Collections.sort(ints);
        System.out.println(Collections.binarySearch(ints, 6));
        System.out.println(Collections.binarySearch(ints, 7));
        ints.add(-Collections.binarySearch(ints, 7)-1, 7);
        System.out.println(ints);
    }
}
