package functional;

import java.util.HashMap;
import java.util.Map;
import java.util.function.BiConsumer;
import java.util.function.Consumer;

public class ConsumerEx {
    public static void main(String...args) {
        Consumer<String> c1 = System.out::println;
        Consumer<String> c2 = x -> System.out.println(x);

        c1.accept("Test Data 1");
        c2.accept("Test Data 2");

        System.out.println("Biconsumer");
        Map<String, Integer> map = new HashMap<>();
        BiConsumer<String, Integer> b1 = map::put;
        BiConsumer<String, Integer> b2 = (k,v) -> map.put(k,v);

        b1.accept("chiken", 7);
        b2.accept("chick", 1);
        System.out.println(map);

        Map<String, String> map1 = new HashMap<>();
        BiConsumer<String,String> b3 = map1::put;
        BiConsumer<String, String> b4 = (k,v) -> map1.put(k,v);
        b3.accept("chiken", "Chuck");
        b4.accept("chick", "Tweep");
        System.out.println(map1);
    }
}
