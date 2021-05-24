package patterns.creational.singleton;

/**
 * The singleton pattern is a creational pattern focused on creating only one instance of an object in memory within
 * an application, sharable by all classes and threads within the application.
 */
public class HayStorage {
    private int quantity = 0;
    /** having private constructor we have marked implicitly this class final */
    private HayStorage() {}
    private static final HayStorage instance = new HayStorage();

    public static HayStorage getInstance() {
        return instance;
    }

    public synchronized void addHay(int amount) {
        quantity += amount;
    }

    public synchronized boolean removeHay(int amount) {
        if (quantity < amount) return false;
        quantity -=amount;
        return true;
    }

    public synchronized int getHayQuantity() {
        return quantity;
    }
}
