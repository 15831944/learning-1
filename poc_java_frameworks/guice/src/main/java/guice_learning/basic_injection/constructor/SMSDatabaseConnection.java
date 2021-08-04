package guice_learning.basic_injection.constructor;

public class SMSDatabaseConnection {
    private String name;
    public SMSDatabaseConnection() {
        name = "databaseConnection";
    }

    public String getName() {
        return name;
    }
}
