package functional;

import java.util.function.BiPredicate;
import java.util.function.Predicate;

public class PredicateEx {
    public static void main(String...args) {
        Predicate<String> p1 = String::isEmpty;
        Predicate<String> p2 = x -> x.isEmpty();

        System.out.println(p1.test(""));
        System.out.println(p2.test(""));

        System.out.println("Bipredicate");
        BiPredicate<String,String> b1 = String::startsWith;
        BiPredicate<String,String> b2 = (string,prefix) -> string.startsWith(prefix);

        System.out.println(b1.test("chicken", "chick"));
        System.out.println(b2.test("chicken", "chick"));

        System.out.println("Predicate Chain");
        Predicate<String> egg = s -> s.contains("egg");
        Predicate<String> brown = s -> s.contains("brown");
        Predicate<String> brownEggs = egg.and(brown);
        Predicate<String> otherEggs = egg.and(brown.negate());
        System.out.println(brownEggs.test("egg brown"));
        System.out.println(brownEggs.test("egg white"));
        System.out.println(otherEggs.test("egg white"));
    }
}
