package certification.concurency.normalthread;

public class PrintData implements Runnable{

	public PrintData() {
		// TODO Auto-generated constructor stub
	}
	
	public void run() {
		for(int i = 0; i < 3;i++) {
			System.out.println("Printing data " + i);
		}
	}

	public static void main(String[] args) {
		(new Thread(new PrintData())).start();
	}
}
