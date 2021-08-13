package certification.streams.ocjp.parallel;

import java.util.Arrays;

public class ParallelStreamEx {
    public static void main(String...args) {
        Arrays.asList(1,2,3,4,5,6)
                .stream()
                .forEach(s -> System.out.print(s+" "));

        System.out.println("\nSame with parallel streams");
        Arrays.asList(1,2,3,4,5,6)
                .parallelStream()
                .forEach(s -> System.out.print(s+" "));
        System.out.println("\nSame with parallel streams and foreachordered");
        Arrays.asList(1,2,3,4,5,6)
                .parallelStream()
                .forEachOrdered(s -> System.out.print(s+" "));
    }
}
