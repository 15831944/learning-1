package patterns.singleton;

/**
 * Lazy instantiation with double checking locking
 */
public class VisitorTicketTrackerDoubleChecking {

    private  static volatile VisitorTicketTrackerDoubleChecking instance;

    private VisitorTicketTrackerDoubleChecking() {

    }

    public static VisitorTicketTrackerDoubleChecking getInstance() {
        if(instance == null) {
            synchronized (VisitorTicketTrackerDoubleChecking.class) {
                if (instance == null)
                    instance = new VisitorTicketTrackerDoubleChecking();
            }
        }
        return instance;
    }
}
