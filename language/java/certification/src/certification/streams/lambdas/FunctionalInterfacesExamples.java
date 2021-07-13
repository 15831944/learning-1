package certification.streams.lambdas;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.function.BiConsumer;
import java.util.function.BiFunction;
import java.util.function.BiPredicate;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class FunctionalInterfacesExamples {

	public FunctionalInterfacesExamples() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		FunctionalInterfacesExamples examples = new FunctionalInterfacesExamples();
		examples.suppliers();
		examples.consumers();
		examples.predicates();
		examples.functions();
	}

	private void functions() {
		Function<String,String> f1 = (x) -> x.toLowerCase();
		System.out.println(f1.apply("AAAA"));
		BiFunction<String,String,String> f2 = (x,y) -> x +  " and " +y;
		System.out.println(f2.apply("me", "you"));
		TriFunction<String,String,String,String> f3 = (x,y,z) -> x + " " + y + " " + z;
		System.out.println(f3.apply("me", "and", "you"));
		
	}

	private void predicates() {
		Predicate<String> p1 = String::isEmpty;
		System.out.println(p1.test(""));
		System.out.println(p1.test("aa"));
		BiPredicate<String, String> bp1 = (string, x) -> string.contains(x);
		System.out.println(bp1.test("abcde", "cd"));
		Predicate<String> egg = s -> s.contains("egg");
		Predicate<String> brown = s -> s.contains("brown");
		Predicate<String> brownEgg= egg.and(brown);
		System.out.println(brownEgg.test("egg are brown"));
	}

	private void consumers() {
		Consumer<String> c1 = System.out::println;
		Consumer<String> c2 = (x) -> System.out.println(x);
		BiConsumer<String,String> bc1 = (x,y) -> System.out.println(x + " and " +y);
		c1.accept("me");
		c2.accept("you");
		bc1.accept("me", "you");
		Map<String, Integer> map1 = new HashMap<String, Integer>();
		BiConsumer<String, Integer> bc2 = map1::put;
		bc2.accept("me", 1);
		bc2.accept("you", 2);
		System.out.println(map1);
		bc2 = (x,y) -> map1.put(x, y);
		bc2.accept("one", 3);
		bc2.accept("two", 4);
		System.out.println(map1);
		
	}

	private void suppliers() {
		Supplier<ArrayList<String>> s1 = ArrayList<String>::new;
		ArrayList<String> str1 = s1.get();
		System.out.println(str1.toString() + " size = " + str1.size() + " and lambda " + s1);
	}
	

}
