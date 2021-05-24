package patterns.creational.factory;

public class Pallets extends Food {
    public Pallets(int quantity) {
        super(quantity);
    }
    public void consumed() {
        System.out.println("Pallets eaten: " + getQuantity());
    }
}
