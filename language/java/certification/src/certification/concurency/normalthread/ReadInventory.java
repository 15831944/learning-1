package certification.concurency.normalthread;

public class ReadInventory extends Thread{

	@Override
	public void run() {
		System.out.println("Zero Inventory");
	}
	public ReadInventory() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		new ReadInventory().start();
	}

}
