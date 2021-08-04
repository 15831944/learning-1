package certification.concurency.ocjp.oldway;

public class ReadInventoryThread extends  Thread{
    public void run() {
        System.out.println("Read inventory");
    }
    public static void main(String...args) {
        (new ReadInventoryThread()).start();
    }
}
