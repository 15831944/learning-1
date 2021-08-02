package certification.exceptions.ocjp.autocloseabble;

class ExampleOne implements AutoCloseable {
    private String message ="one";
    public ExampleOne() {

    }
    public ExampleOne(String message) {
        this.message = message;
    }
    public void close() throws IllegalStateException {
        throw new IllegalStateException("Cage door does not close " + message);
    }
}
class ExampleTwo implements AutoCloseable {
    public void close() throws  Exception {
        throw new Exception("Cage door does not close two");
    }
}
class ExampleThree implements AutoCloseable {
    static int COUNT = 0;
    public void close() {
        COUNT++;
    }
    public static int getCount() {
        return COUNT;
    }
}
public class AutoCloseableEx {
    public static void main(String...args) {
        try (ExampleOne exampleOne = new ExampleOne()) {
            System.out.println("Working to close");
        } catch (IllegalStateException e) {
            System.out.println(e.getLocalizedMessage());
        }
        try (ExampleTwo exampleTwo = new ExampleTwo()) {
            System.out.println("Working two to close");
        } catch (Exception e) {
            System.out.println(e.getLocalizedMessage());
        }
        try (ExampleThree exampleThree = new ExampleThree()) {
            System.out.println("Working three to close");
        }
        System.out.println("Called " + ExampleThree.getCount() + " times.");
        try (ExampleOne exampleOne = new ExampleOne()) {
            throw new IllegalStateException("turkeys ran off");
        } catch (IllegalStateException e) {
            System.out.println("caught: " + e.getMessage());
            for (Throwable t : e.getSuppressed()) {
                System.out.println(t.getMessage());
            }
        }
        try (ExampleOne t1 = new ExampleOne("1"); ExampleOne t2 = new ExampleOne("2")) {
            System.out.println("turkeys ran off");
        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
            for (Throwable t : e.getSuppressed()) {
                System.out.println(t.getMessage());
            }
        }
    }
}
