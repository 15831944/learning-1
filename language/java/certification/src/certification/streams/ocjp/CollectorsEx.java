package streams.ocjp;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CollectorsEx {
    public static void main(String...args) {
        List<String> animals = Arrays.asList("lions", "tigers", "bears");
        Stream<String> animalsStream =  animals.stream();
        String resultStr = animalsStream.collect(Collectors.joining(", "));
        System.out.println(resultStr); //lions, tigers, bears

        animalsStream = animals.stream();
        Double resultD = animalsStream.collect(Collectors.averagingInt(String::length));
        System.out.println(resultD);//5.333333333333333

        animalsStream = animals.stream();
        TreeSet<String> resultTreeSet = animalsStream.filter(s -> s.startsWith("t")).collect(Collectors.toCollection(TreeSet::new));
        System.out.println(resultTreeSet); //[tiger]

        System.out.println("Collecting into Maps");
        animalsStream = animals.stream();
        Map<String,Integer> mapSI = animalsStream.collect(Collectors.toMap(s -> s, String::length));
        System.out.println(mapSI);//{lions=5,bears=5,tigers=6}
        System.out.println(mapSI.getClass()); //HashMap

        animalsStream = animals.stream();
        Map<Integer,String> mapIS = animalsStream.collect(Collectors.toMap(String::length, k->k, (s1,s2) -> s1 + "," + s2)); //keymapper,valuemapper, mergefunction
        System.out.println(mapIS); //{5=lions,bears,6=tigers}
        System.out.println(mapIS.getClass()); //HashMap

        animalsStream = animals.stream();
        mapIS = animalsStream.collect(Collectors.toMap(String::length, k->k, (s1,s2) -> s1 + "," + s2,TreeMap::new)); //keymapper,valuemapper, mergefunction, typeofmap
        System.out.println(mapIS); //{5=lions,bears,6=tigers}
        System.out.println(mapIS.getClass()); //TreeMap

        System.out.println("Collecting into map of collections");
        animalsStream = animals.stream();
        Map<Integer,List<String>> mapILS = animalsStream.collect(Collectors.groupingBy(String::length));
        System.out.println(mapILS); ///{5=[lions,bears],6=[tigers]}
        System.out.println(mapILS.getClass());//HashMap
        animalsStream = animals.stream();
        Map<Integer,Set<String>> mapISS = animalsStream.collect(Collectors.groupingBy(String::length,Collectors.toSet()));
        System.out.println(mapISS); ///{5=[lions,bears],6=[tigers]}
        System.out.println(mapISS.getClass()); //HashMap
        animalsStream = animals.stream();
        mapISS = animalsStream.collect(Collectors.groupingBy(String::length,TreeMap::new, Collectors.toSet()));
        System.out.println(mapISS); ///{5=[lions,bears],6=[tigers]}
        System.out.println(mapISS.getClass()); //TreeMap

        animalsStream = animals.stream();
        mapILS = animalsStream.collect(Collectors.groupingBy(String::length,TreeMap::new, Collectors.toList()));
        System.out.println(mapILS); ///{5=[lions,bears],6=[tigers]}
        System.out.println(mapILS.getClass());//TreeMap

        animalsStream = animals.stream();
        Map<Boolean,List<String>> mapBLS = animalsStream.collect(Collectors.partitioningBy(s -> s.length() <= 5));
        System.out.println(mapBLS);//{false=[tigers],true=[lions,bears]}

        animalsStream = animals.stream();
        Map<Integer,Optional<Character>> mapIOC = animalsStream.collect(Collectors.groupingBy(String::length,
                Collectors.mapping((String s) -> s.charAt(0), Collectors.minBy(Comparator.naturalOrder()))));
        System.out.println(mapIOC); //{5=Optional[b], 5=Optional[t]}
    }
}
