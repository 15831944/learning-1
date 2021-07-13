/**
 * 
 */
package certification.streams;

import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.stream.Stream;

/**
 * @author Gabriel
 *
 */
public class SimpleStreams {

	/**
	 * 
	 */
	public SimpleStreams() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SimpleStreams main = new SimpleStreams();
		main.s1();
	}

	private void s1() { 
		Stream<String> s1 = Stream.of("one12", "1one", "one2");
		Optional<String> min = s1.min((x1,x2) -> x1.length()-x2.length());
		min.ifPresent(System.out::println);
		
		Optional<?> minEmpty = Stream.empty().min((x1,x2) -> 0);
		System.out.println("optional empty stream empty elements = " + minEmpty.isPresent());
		
		Stream<String> infinite = Stream.generate(() -> "chimp");
		infinite.findAny().ifPresent(System.out::println);
		
		Predicate<String> pred = (x) -> Character.isLetter(x.charAt(0));
		
		List<String> list = Arrays.asList("one1", "1", "one2");
		System.out.println("anyMatch=" + list.stream().anyMatch(pred));
		System.out.println("allMatch=" + list.stream().allMatch(pred));
		System.out.println("noneMatch=" + list.stream().noneMatch(pred));
		
		infinite = Stream.generate(() -> "chimp");
		System.out.println("infinite anyMatch=" + infinite.anyMatch(pred));
		
		//consumer
		Consumer<String> c1 = (x) -> System.out.print(x + " ");
		list.stream().forEach(c1);
		
		System.out.println();
		s1 = Stream.of("1","2","3");
		String rezStr = s1.reduce("", (x,y) -> x + y);
		System.out.println("reduce rezult = " + rezStr);
		Stream<Integer> s2 = Stream.of(1,2,3);
		Integer rezInt = s2.reduce(1, (x,y) -> x*y);
		System.out.println("reduce rezult = " + rezInt);
		
		
	}

}
