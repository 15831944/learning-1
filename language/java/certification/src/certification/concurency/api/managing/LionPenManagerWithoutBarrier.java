package certification.concurency.api.managing;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class LionPenManagerWithoutBarrier {

	private void removeAnimals() {
		System.out.println("Removing animals");
	}
	
	private void cleanPen() {
		System.out.println("Clean the pen");
	}
	
	private void addAnimals() {
		System.out.println("Adding animals");
	}
	public void performTask() {
		removeAnimals();
		cleanPen();
		addAnimals();
	}
	public static void main(String[] args) {
		ExecutorService service = null;
		try {
			service = Executors.newFixedThreadPool(4);
			LionPenManagerWithoutBarrier manager = new LionPenManagerWithoutBarrier();
			for (int i = 0;i < 4; i++) {
				service.submit(() -> manager.performTask());
			}
		} finally {
			if (service != null) {
				service.shutdown();
			}
		}

	}

}
