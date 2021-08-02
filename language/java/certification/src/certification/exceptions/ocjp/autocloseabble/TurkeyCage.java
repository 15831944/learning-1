package exceptions.ocjp;

public class TurkeyCage implements AutoCloseable{
    public void close() throws Exception{
        System.out.println("Close Gate");
        throw new Exception("Cage door does not close");
    }
    public static void main(String...args) {
        try (TurkeyCage t = new TurkeyCage())  {
            System.out.println("put turkeys in");
        }
        catch (Exception e) {
            System.out.println(e.getLocalizedMessage());
        }
        finally {
            System.out.println("Leave off the job.");
        }
    }
}
