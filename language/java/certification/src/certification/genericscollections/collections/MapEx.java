package genericscollections.collections;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import java.util.function.BiFunction;
import java.util.function.Function;

public class MapEx {
    public static void main(String...args) {
        Map<String, String> mapH = new HashMap<>();
        mapH.put("koala", "bamboo");
        mapH.put("cat", "kittycat");
        mapH.put("giraffe","leaf");
        System.out.println(mapH.get("cat"));//kittycat
        for (String key : mapH.keySet()) {
            System.out.print(key + ","); //arbitrary
        }
        System.out.println();
        Map<String, String> mapT = new TreeMap<>();
        mapT.put("koala", "bamboo");
        mapT.put("cat", "kittycat");
        mapT.put("giraffe","leaf");
        System.out.println(mapT.get("cat"));//kittycat
        for (String key : mapT.keySet()) {
            System.out.print(key + ","); //cat, giraffe, koala
        }
        System.out.println();
        BiFunction<String, String, String> mapper = (v1, v2) -> v1.length() > v2.length() ? v1: v2;
        Map<String, String> favorites = new HashMap<>();
        favorites.put("Jenny", "Bus Tour");
        favorites.put("Tom", "Tram");
        String jenny = favorites.merge("Jenny", "Skyride", mapper);
        String tom = favorites.merge("Tom", "Skyride", mapper);
        System.out.println(favorites); // {Tom=Skyride, Jenny=Bus Tour}
        System.out.println(jenny);     // Bus Tour
        System.out.println(tom);       // Skyride

        BiFunction<String, String, String> mapper1 = (v1, v2) -> null;
        Map<String, String> favorites1 = new HashMap<>();
        favorites1.put("Jenny", "Bus Tour");
        favorites1.put("Tom", "Bus Tour");
        favorites1.merge("Jenny", "Skyride", mapper1);
        favorites1.merge("Sam","Skyride", mapper1);
        System.out.println(favorites1); //{Tom=Bus Tour, Sam=Skyride}
        Map<String, Integer> counts = new HashMap<>();
        counts.put("Jenny", 1);

        BiFunction<String, Integer, Integer> mapper2 = (k, v) -> v + 1;
        System.out.println(counts); // {Jenny=2}
        System.out.println(counts.computeIfPresent("Jenny", mapper2)); // 2
        System.out.println(counts.computeIfPresent("Sam", mapper2)); // null

        Map<String, Integer> counts1 = new HashMap<>();
        counts1.put("Jenny", 15);
        counts1.put("Tom", null);

        Function<String, Integer> mapper3 = (k) -> 1;
        System.out.println(counts1.computeIfAbsent("Jenny", mapper3)); // 15
        System.out.println(counts1.computeIfAbsent("Sam", mapper3)); // 1
        System.out.println(counts1.computeIfAbsent("Tom", mapper3)); // 1
        System.out.println(counts1); // {Tom=1, Jenny=15, Sam=1}
    }
}
