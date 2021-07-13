package certification.concurency.normalthread;

public class RunAll {

	public RunAll() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		System.out.println("Begin");
		new ReadInventory().start();
		(new Thread(new PrintData())).start();
		new ReadInventory().start();
		System.out.println("End");
	}

}
