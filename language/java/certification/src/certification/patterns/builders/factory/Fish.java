package certification.patterns.builders.factory;

public class Fish extends Food{
    public Fish(int quantity) {
        super(quantity);
    }

    public void consumed() {
        System.out.println("Fish eaten:" + getQuantity());
    }
}
