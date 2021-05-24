package patterns.creational.factory;

/**
 * Factory pattern sometimes referred to as the factory method pattern.
 * Is a creation pattern based on the idea of using factory class to produce
 * instance objects based on a set of input parameters.
 * It is similar to the builder pattern, although it is focused on supporting
 * class polymorphism.
 */
public class FoodFactory {
    public static Food getFood(String animalName) {
        switch (animalName) {
            case "zebra": return new Hay(100);
            case "rabbit": return new Pallets(5);
            case "goat": return new Pallets(30);
            case "polar bear": return new Fish(10);
        }
        //good practice to throw an exception if no matching subclass could be found
        throw new UnsupportedOperationException("Unsupported animal: " + animalName);
    }
}
