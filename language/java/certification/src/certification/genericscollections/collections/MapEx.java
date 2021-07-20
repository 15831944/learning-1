package genericscollections.collections;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

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
    }
}
