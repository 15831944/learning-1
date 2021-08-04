package certification.design.interfaces.functional;

import java.util.function.Predicate;

public class FindMatchingAnimals {
    private static void print(Animal animal, CheckTrait checkTrait) {
        if (checkTrait.test(animal))
            System.out.println(animal);
    }

    private static void print1(Animal animal, Predicate<Animal> checkTrait) {
        if (checkTrait.test(animal))
            System.out.println(animal);
    }

    public static void main(String...args) {
        print(new Animal("fish", false, true), a->a.canHop());
        print(new Animal("kangaroo",true, false), a -> a.canHop());
        print1(new Animal("fish", false, true), a->a.canHop());
        print1(new Animal("kangaroo",true, false), a -> a.canHop());
    }
}
