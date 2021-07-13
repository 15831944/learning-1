package certification.concurency.api;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ZooInfoSubmit {

	public ZooInfoSubmit() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		ExecutorService service = null;
		try {
			service = Executors.newSingleThreadExecutor();
			System.out.println("Begin");
			Future<?> first = service.submit(() -> {
				System.out.println("Printing zero inventory !");
			});
			Future<?> second = service.submit(() -> {
				for(int i = 0; i < 3; i++) {
					System.out.println("Printing data " + i);
				}
			});
			Future<?> third = service.submit(() -> {
				System.out.println("Printing zero inventory !");
			});
			System.out.println("End");
			System.out.println("first is done =" + first.isDone());
			System.out.println("second is done =" + second.isDone());
			System.out.println("third is done =" + third.isDone());
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
