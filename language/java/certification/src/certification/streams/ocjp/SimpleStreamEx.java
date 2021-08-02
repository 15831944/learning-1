package certification.streams.ocjp;

import java.util.*;
import java.util.function.BinaryOperator;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class SimpleStreamEx {
    public static void main(String...args) {
        Stream<String> stream1 = Stream.of("monkey", "gorilla", "lion");
        System.out.println(stream1.count()); //3
        stream1 = Stream.of("monkey", "gorilla", "lion");
        Optional<String> min = stream1.min((s1, s2) -> s1.length() - s2.length());
        min.ifPresent(System.out::println); //lion
        Optional<?> minEmpty = Stream.empty().min((s1,s2) -> 0);
        System.out.println(minEmpty.isPresent());//false
        stream1 = Stream.of("monkey", "gorilla", "lion");
        Stream<String> infinite = Stream.generate(() -> "chimp");
        stream1.findAny().ifPresent(System.out::println); //monkey
        infinite.findAny().ifPresent(System.out::println); //chimp

        System.out.println("Stream match operation");
        List<String> list = Arrays.asList("monkey", "2", "chimp");
        infinite = Stream.generate(() -> "chimp");
        Predicate<String> pred = x -> Character.isLetter(x.charAt(0));
        System.out.println(list.stream().anyMatch(pred)); //true
        System.out.println(list.stream().allMatch(pred)); //false
        System.out.println(list.stream().noneMatch(pred)); //false
        System.out.println(infinite.anyMatch(pred)); //true

        System.out.println("ForEach stream operations");
        list.stream().forEach(System.out::print); //monkey2chimp
        System.out.println();
        System.out.println("Another option without calling stream on a collection");
        list.forEach(System.out::println);//monkey2chimp
        System.out.println();

        stream1 = Stream.of("monkey", "gorilla", "lion");
        stream1.forEach(System.out::print); //monkeygorillalion
        System.out.println();

        System.out.println("Classical reduction way");
        List<String>  wolf= Arrays.asList("w","o","l","f");
        String result = "";
        for(String s : wolf)
            result +=s;
        System.out.println(result); //wolf
        System.out.println("Reduce stream operations");
        result = wolf.stream().reduce("", (s,c) -> s + c);
        System.out.println(result);//wolf
        result = wolf.stream().reduce("",String::concat);
        System.out.println(result);//wolf

        Stream<Integer> intStream = Stream.of(3,5,6);
        System.out.println(intStream.reduce(1, (a,b) -> a *b ));

        BinaryOperator<Integer> op = (a, b) -> a *b ;
        Stream<Integer> empty = Stream.empty();
        Stream<Integer> oneElement = Stream.of(3);
        Stream<Integer> threeElements = Stream.of(3,5,6);
        empty.reduce(op).ifPresent(System.out::println); //no output
        oneElement.reduce(op).ifPresent(System.out::println); //3
        threeElements.reduce(op).ifPresent(System.out::println);//90

        threeElements = Stream.of(3,5,6);
        System.out.println(threeElements.reduce(1,op,op)); //90

        System.out.println("Collect on streams");
        StringBuilder word = wolf.stream().collect(StringBuilder::new, StringBuilder::append, StringBuilder::append);
        System.out.println(word); //wolf

        TreeSet<String> set = wolf.stream().collect(TreeSet::new, TreeSet::add, TreeSet::addAll);
        System.out.println(set); //[f,l,o,w]

        set = wolf.stream().collect(Collectors.toCollection(TreeSet::new));
        System.out.println(set); //[f,l,o,w]

        Set<String> set1 = wolf.stream().collect(Collectors.toSet());
        System.out.println(set1); //[f,w,l,o] not sorted ...

        System.out.println("Filter on stream");
        stream1 = Stream.of("monkey", "gorilla", "lion");
        stream1.filter(x -> x.startsWith("m")).forEach(System.out::println);//monkey

        System.out.println("Distinct on stream");
        Stream<String> stream2 = Stream.of("duck","duck","duck","goose");
        stream2.distinct().forEach(System.out::print);//duckgoose
        System.out.println();

        System.out.println("Limit and skip on stream");
        Stream<Integer> infiniteInts = Stream.iterate(1, n -> n + 1);
        infiniteInts.skip(5).limit(2).forEach(System.out::print);//67

        System.out.println("Map and flatMap on stream");
        stream1 = Stream.of("monkey", "gorilla", "lion");
        stream1.map(String::length).forEach(System.out::print);//674
        System.out.println();

        List<String> zeroList = Arrays.asList();
        List<String> oneList = Arrays.asList("Bonobo");
        List<String> twoList = Arrays.asList("Mama Gorilla", "Baby Gorilla");
        Stream<List<String>> animals = Stream.of(zeroList, oneList, twoList);
        animals.flatMap(l -> l.stream()).forEach(System.out::println);

        System.out.println("Sort on stream");
        stream1 = Stream.of("brown-","bear-");
        stream1.sorted().forEach(System.out::print);//bear-brown
        System.out.println();

        stream1 = Stream.of("brown-","bear-");
        stream1.sorted(Comparator.reverseOrder()).forEach(System.out::print); //brown-bear-
        System.out.println();

        System.out.println("Peek on stream");
        stream1 = Stream.of("black bear", "brown bear", "grizzly");
        long count = stream1.filter(s -> s.startsWith("g")).peek(System.out::println).count(); //grizzly
        System.out.println(count); //1

        List<Integer> numbers = new ArrayList<>();
        List<Character> letters = new ArrayList<>();
        numbers.add(1);
        letters.add('a');
        StringBuilder builder = new StringBuilder();
        Stream<List<?>> good = Stream.of(numbers, letters);
        good.peek(l -> builder.append(l)).map(List::size).forEach(System.out::print); //11
        System.out.println(builder);//[1][a]
        Stream<List<?>> bad = Stream.of(numbers, letters);
        bad.peek(l -> l.remove(0)).map(List::size).forEach(System.out::print);//00

    }
}
