package design.interfaces.functional;

public class FindMatchingAnimals {
    private static void print(Animal animal, CheckTrait checkTrait) {
        if (checkTrait.test(animal))
            System.out.println(animal);
    }

    public static void main(String...args) {
        print(new Animal("fish", false, true), a->a.canHop());
        print(new Animal("kangaroo",true, false), a -> a.canHop());
    }
}
