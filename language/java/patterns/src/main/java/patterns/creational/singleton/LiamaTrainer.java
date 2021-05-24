package patterns.creational.singleton;

/**
 * example how to use the singleton.
 */
public class LiamaTrainer {

    public static void main(String...args) {
        LiamaTrainer trainer = new LiamaTrainer();
        trainer.feedLiamas(2);
    }
    public boolean feedLiamas(int numberOfLiamas) {
        int amountNeeded = 5 * numberOfLiamas;
        HayStorage hayStorage = HayStorage.getInstance();
        if (hayStorage.getHayQuantity() < amountNeeded) {
            hayStorage.addHay(amountNeeded + 10);
        }
        boolean fed = hayStorage.removeHay(amountNeeded);
        if (fed) {
            System.out.println("Liamas have been fed");
        }
        return fed;
    }
}
