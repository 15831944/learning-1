/**
 * 
 */
package certification.streams;

import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * @author gdimitriu
 *
 */
public class StreamsTests {

	/**
	 * 
	 */
	public StreamsTests() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		StreamsTests tests = new StreamsTests();
		tests.collectors();
		tests.intermediates();

	}

	private void intermediates() {
		List<String> data = Arrays.asList("me", "you", "boby");
		Stream<String> streamS1 = data.stream();
		streamS1.filter(x -> x.startsWith("y")).forEach(System.out::println);
		System.out.println(":duplicates");
		List<String> dataDuplicates = Arrays.asList("me","me","you", "you", "boby");
		streamS1 = dataDuplicates.stream();
		streamS1.forEach(System.out::println);
		System.out.println(":without duplicates");
		streamS1 = dataDuplicates.stream();
		streamS1.distinct().forEach(System.out::println);
		System.out.print(":integers as list=");
		List<Integer> dataInt = Arrays.asList(1,2,3,4,5,6,7);
		Stream<Integer> streamI1 = dataInt.stream();
		streamI1.skip(2).limit(3).forEach(System.out::print);
		System.out.print("\n:map=");
		streamS1 = data.stream();
		streamS1.map(x -> x.length()).forEach(System.out::print);
	}

	private void collectors() {
		List<String> data = Arrays.asList("a","b","c");
		
		Stream<String> streamS1 = data.stream();
		StringBuilder sb1 = streamS1.collect(StringBuilder::new, StringBuilder::append, StringBuilder::append);
		System.out.println(sb1);
		
		streamS1 = data.stream();
		TreeSet<String> ts1 = streamS1.collect(TreeSet::new, TreeSet::add, TreeSet::addAll);
		System.out.println(ts1);
		
		streamS1 = data.stream();
		ts1 = streamS1.collect(Collectors.toCollection(TreeSet::new));
		System.out.println(ts1);
		
		streamS1 = data.stream();
		Set<String> sets1 = streamS1.collect(Collectors.toSet());
		System.out.println(sets1);
	}

}
