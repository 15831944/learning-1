package patterns.creational.singleton;

/**
 * Lazy initialization of the singleton with double checking.
 */
public class VisitorTicketTrackerLazyDouble {
    private static volatile VisitorTicketTrackerLazyDouble instance;
    private VisitorTicketTrackerLazyDouble(){}
    public static VisitorTicketTrackerLazyDouble getInstance() {
        if (instance == null) {
            synchronized (VisitorTicketTrackerLazy.class) {
                if (instance == null) {
                    instance = new VisitorTicketTrackerLazyDouble();
                }
            }
        }
        return instance;
    }

    //data access methods

}
