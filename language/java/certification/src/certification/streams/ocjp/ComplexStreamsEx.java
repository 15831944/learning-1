package streams.ocjp;

import java.util.*;
import java.util.function.Function;
import java.util.function.IntFunction;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class ComplexStreamsEx {
    public static void main(String...args) {
        System.out.println("Before JAVA 8");
        List<String> list = Arrays.asList("Toby", "Anna", "Leroy", "Alex");
        List<String> filtered = new ArrayList<>();
        for (String name : list) {
            if (name.length() == 4)
                filtered.add(name);
        }
        Collections.sort(filtered);
        Iterator<String> iter = filtered.iterator();
        if (iter.hasNext()) System.out.println(iter.next());
        if (iter.hasNext()) System.out.println(iter.next());
        System.out.println("Using streams");
        list.stream().filter(n -> n.length() == 4).sorted().limit(2).forEach(System.out::println);
        /* wrong example it will block
        Stream.generate(() -> "Elsa")
                .filter(n -> n.length() == 4)
                .sorted()
                .limit(2)
                .forEach(System.out::println);
         */
        Stream.generate(() -> "Elsa")
                .filter(n -> n.length() == 4)
                .limit(2)
                .sorted()
                .forEach(System.out::println);
        /* another example that it is hanging until program is killed because there is no match elements
        Stream.generate(() -> "Olaf Lazisson")
                .filter(n -> n.length() == 4)
                .limit(2)
                .sorted()
                .forEach(System.out::println);
         */
        Stream<Integer> infinite = Stream.iterate(1, x -> x + 1);
        infinite.limit(5)
                .peek(System.out::print) //for debug purpose
                .filter(x -> x % 2 == 1)
                .forEach(System.out::print);  // 135 // with peek 11233455
        System.out.println();
        infinite = Stream.iterate(1, x -> x + 1);
        infinite.filter(x -> x % 2 == 1)
                .peek(System.out::print) //for debug purpose
                .limit(5)
                .forEach(System.out::print);  // 135 // with peek 1133557799 only odd numbers
        System.out.println();

        System.out.println("Working with primitives");
        Stream<Integer> streamInt = Stream.of(1,2,3);
        System.out.println(streamInt.reduce(0, (x,y) -> x + y));//6
        //better way to do it
        streamInt = Stream.of(1,2,3);
        System.out.println(streamInt.mapToInt(x -> x).sum());//6

        IntStream intStream= IntStream.of(1, 2, 3);
        OptionalDouble avg = intStream.average();
        System.out.println(avg.getAsDouble()); //2

        Stream<String> objStream = Stream.of("penguin", "fish");
        intStream = objStream.mapToInt(s -> s.length());
        intStream.forEach(System.out::print);
        System.out.println();
        //similar but without lambda
        objStream = Stream.of("penguin", "fish");
        intStream = objStream.mapToInt(new ToIntFunction<String>() {

            @Override
            public int applyAsInt(String s) {
                return s.length();
            }
        });
        intStream.forEach(System.out::print);
        System.out.println();
        objStream = Stream.of("penguin", "fish");
        intStream = objStream.mapToInt(s -> s.length());
        objStream = intStream.mapToObj(new IntFunction<String>() {
            @Override
            public String apply(int i) {
                return new String("t").repeat(i);
            }
        });
        objStream.forEach(System.out::println);

        System.out.println("Using optional with primitive streams");

        intStream = IntStream.rangeClosed(1,10);
        OptionalDouble optional = intStream.average();
        optional.ifPresent(System.out::println);
        System.out.println(optional.getAsDouble());
        System.out.println(optional.orElseGet(() -> Double.NaN));

        intStream = IntStream.rangeClosed(1,10);
        System.out.println("Range is " + ComplexStreamsEx.range(intStream));

        System.out.println("Linking stream to underlying data");
        List<String> cats = new ArrayList<>();
        cats.add("Miti");
        cats.add("Pufosenie");
        Stream<String> stream = cats.stream();
        cats.add("Grasu");
        System.out.println("There are " + stream.count() + " into the stream"); //3

    }

    public static int range(IntStream ints) {
        IntSummaryStatistics stats = ints.summaryStatistics();
        if (stats.getCount() == 0)
            throw new RuntimeException();
        return stats.getMax() - stats.getMin();
    }
}
