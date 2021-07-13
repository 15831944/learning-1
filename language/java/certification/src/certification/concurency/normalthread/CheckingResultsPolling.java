package certification.concurency.normalthread;

public class CheckingResultsPolling {

	public static int counter = 0; 
	public CheckingResultsPolling() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws InterruptedException {
		new Thread(() -> {
			for (int i=0;i < 1000; i++) CheckingResultsPolling.counter++;
		}).start();
		while(CheckingResultsPolling.counter < 200) {
			System.out.println("Not reached yet!");
			Thread.sleep(1000);
		}
		System.out.println("Reached !");
	}
}
