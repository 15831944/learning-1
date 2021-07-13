package certification.lambdas;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class TraditionalSearch {

	public static void main(String[] args) {
		List<Animal> animals = new ArrayList<Animal>();
		animals.add(new Animal("fish", false, true));
		animals.add(new Animal("kangaroo", true, false));
		animals.add(new Animal("rabbit", true, false));
		animals.add(new Animal("turtle", false, true));
		
		print(animals, new CheckIfHopper());
		
		System.out.println("lambda");
		
		print(animals, a -> a.canHop());
		print(animals, a -> a.canSwim());
		System.out.println("with predicates");
		printPredicates(animals, a -> a.canHop());
	}

	private static void printPredicates(List<Animal> animals, Predicate<Animal> checker) {
		for (Animal animal : animals) {
			if (checker.test(animal)) {
				System.out.print(animal + " ");
			}
		}
	}
	private static void print(List<Animal> animals, CheckTrait checker) {
		for (Animal animal : animals) {
			if (checker.test(animal)) {
				System.out.print(animal + " ");
			}
		}
		System.out.println();
	}
}
