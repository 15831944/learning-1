package certification.concurency.api.raceconditions;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SheepManagerRace {

	private int sheepCounter = 0;
	private void incrementAndReport() {
		System.out.print((++sheepCounter) + " ");
	}
	
	public static void main(String[] args) {
		ExecutorService service = null;
		try {
			service = Executors.newFixedThreadPool(20);
			SheepManagerRace manager = new SheepManagerRace();
			for (int i = 0; i < 10; i++) {
				service.submit(() -> manager.incrementAndReport());
			}
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
