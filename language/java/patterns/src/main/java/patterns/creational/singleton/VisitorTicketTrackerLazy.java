package patterns.creational.singleton;

/**
 * Lazy initialization of the singleton
 */
public class VisitorTicketTrackerLazy {
    private static VisitorTicketTrackerLazy instance;
    private VisitorTicketTrackerLazy(){}
    public static VisitorTicketTrackerLazy getInstance() {
        if (instance == null) {
            instance = new VisitorTicketTrackerLazy(); //no thread safe without synchronized but is slow
        }
        return instance;
    }

    //data access methods

}
