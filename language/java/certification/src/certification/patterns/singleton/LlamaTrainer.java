package patterns.singleton;

public class LlamaTrainer {
    public boolean feedLlama(int numberOfLlama) {
        int amountNeed = 5 * numberOfLlama;
        HayStorage hayStorage = HayStorage.getInstance();
        if (hayStorage.getHayQuantity() < amountNeed) {
            hayStorage.addHay(amountNeed + 10);
        }
        boolean fed = hayStorage.removeHay(amountNeed);
        if (fed)
            System.out.println("Llamas have been fed");
        return fed;
    }

    public static void main(String...args) {
        LlamaTrainer trainer = new LlamaTrainer();
        trainer.feedLlama(10);
    }
}
