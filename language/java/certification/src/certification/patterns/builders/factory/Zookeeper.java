package certification.patterns.builders.factory;

public class Zookeeper {
    public static void main(String...args) {
        final Food food = FoodFactory.getFood("polar bear");
        food.consumed();
    }
}
