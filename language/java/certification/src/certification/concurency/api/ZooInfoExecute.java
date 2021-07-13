package certification.concurency.api;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ZooInfoExecute {

	public ZooInfoExecute() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		ExecutorService service = null;
		try {
			service = Executors.newSingleThreadExecutor();
//			service = Executors.newFixedThreadPool(3);
			System.out.println("Begin");
			service.execute(() -> {
				System.out.println("Printing zero inventory !");
			});
			service.execute(() -> {
				for(int i = 0; i < 3; i++) {
					System.out.println("Printing data " + i);
				}
			});
			service.execute(() -> {
				System.out.println("Printing zero inventory !");
			});
			System.out.println("End");
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
