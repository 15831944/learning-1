package certification.concurency.api.parallelstream;

import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.ConcurrentSkipListSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Redunctions {

	
	public static void main(String[] args) {
		System.out.println("Serial predictible findAny");
		List<Integer> data = Arrays.asList(1,2,3,4,5,6);
		System.out.println(data.stream().findAny().get());
		System.out.println("Parallel unpredictible findAny");
		System.out.println(data.parallelStream().findAny().get());
		System.out.println("Serial flow to generate worlf using reduce");
		System.out.println(Arrays.asList('w','o','l','f').stream()
				.reduce("", (c,s1) -> c + s1, (s2,s3) -> s2 + s3));
		System.out.println("Parallel flow to generate worlf using reduce");
		//this is working because:
		//u =combiner.apply(indentity,u)
		//acumulator operation op : (a op b) op c = a op (b op c)
		//combiner operation : combiner.apply(u, accumulator.apply(indentity,t)) = accumulator.apply(u,t)
		System.out.println(Arrays.asList('w','o','l','f').parallelStream()
				.reduce("", (c,s1) -> c + s1, (s2,s3) -> s2 + s3));
		System.out.println("Serial flow to generate aworlf using reduce");
		System.out.println(Arrays.asList('w','o','l','f').stream()
				.reduce("a", (c,s1) -> c + s1, (s2,s3) -> s2 + s3));
		System.out.println("Parallel flow fail to generate aworlf using reduce");
		System.out.println(Arrays.asList('w','o','l','f').parallelStream()
				.reduce("a", (c,s1) -> c + s1, (s2,s3) -> s2 + s3));
		System.out.println("Collect from wolf data using parallel flow to obtain flow");
		Stream<String> stream = Stream.of("w","o","l","f").parallel();
		SortedSet<String> sortedSet = stream.collect(ConcurrentSkipListSet::new, Set::add, Set::addAll);
		System.out.println(sortedSet);
		System.out.println("Collect from wolf data using parallel flow fail to obtain flow");
		stream = Stream.of("w","o","l","f").parallel();
		Set<String >set = stream.collect(Collectors.toSet());
		System.out.println(set);
		
		System.out.println("Grouping and printing the length of the words");
		Stream<String> ohMy = Stream.of("lions","tigers", "bears").parallel();
		ConcurrentMap<Integer, String> map = ohMy
				.collect(Collectors.toConcurrentMap(String::length,k -> k, (s1,s2) -> s1+","+s2));
		System.out.println(map);
		assert(map instanceof java.util.concurrent.ConcurrentHashMap);
		System.out.println("Grouping and printing the length of the words");
		ohMy = Stream.of("lions","tigers", "bears").parallel();
		ConcurrentMap<Integer, List<String>> map1 = ohMy
				.collect(Collectors.groupingByConcurrent(String::length));
		System.out.println(map1);
		assert(map1 instanceof java.util.concurrent.ConcurrentHashMap);
	}

}
