package patterns.singleton;

/**
 * Lazy instantiation which is not thread safe
 */
public class VisitorTicketTracker {

    private  static VisitorTicketTracker instance;

    private VisitorTicketTracker() {

    }

    //add synchronized to be tread safe
    public static VisitorTicketTracker getInstance() {
        if(instance == null) {
            instance = new VisitorTicketTracker(); //not thread safe
        }
        return instance;
    }
}
