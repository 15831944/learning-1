package certification.concurency.api.parallelstream;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class CreatingExecutingPSFor {

	public CreatingExecutingPSFor() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		System.out.println("Serial forEach");
		Arrays.asList(1,2,3,4,5,6,7,8,9).stream().forEach(s -> System.out.print(s + " "));
		System.out.println("\nParallel forEach");
		Arrays.asList(1,2,3,4,5,6,7,8,9).parallelStream().forEach(s -> System.out.print(s + " "));
		System.out.println("\nParallel forEach serial");
		Arrays.asList(1,2,3,4,5,6,7,8,9).parallelStream().forEachOrdered(s -> System.out.print(s + " "));
		System.out.println("\nParallel stream indempotent");
		Arrays.asList("jackal","kangaroo", "lemur")
			.parallelStream().map(s -> {System.out.println(s); return s.toUpperCase();})
			.forEach(System.out::println);
		System.out.println("\n Avoiding Stefull Operation");
		List<Integer> data = Collections.synchronizedList(new ArrayList<>());
		// with new ArrayList<>(); there are missing elements because of the resizing of array by two threads
		Arrays.asList(1,2,3,4,5,6).parallelStream()
			.map(i -> {data.add(i); return i;})
			.forEachOrdered(i -> System.out.print(i + " "));
		System.out.println();
		for (Integer val : data) {
			System.out.print(val + " ");
		}
	}

}
