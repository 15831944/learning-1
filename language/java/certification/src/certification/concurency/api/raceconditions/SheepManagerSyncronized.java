package certification.concurency.api.raceconditions;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SheepManagerSyncronized {

	private int sheepCounter = 0;
	private void incrementAndReport() {
		synchronized(this) {
			System.out.print((++sheepCounter) + " ");
		}
	}
	
	@SuppressWarnings("unused")
	private synchronized void incrementAndReportEquivalent() {
		System.out.print((++sheepCounter) + " ");
	}
	
	public static void main(String[] args) {
		ExecutorService service = null;
		try {
			service = Executors.newFixedThreadPool(20);
			SheepManagerSyncronized manager = new SheepManagerSyncronized();
			for (int i = 0; i < 10; i++) {
				service.submit(() -> manager.incrementAndReport());
			}
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
