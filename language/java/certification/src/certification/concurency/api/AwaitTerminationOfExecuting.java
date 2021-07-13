package certification.concurency.api;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class AwaitTerminationOfExecuting {

	public AwaitTerminationOfExecuting() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws InterruptedException, ExecutionException {
		ExecutorService service = null;
		Future<Integer> first = null;
		Future<Integer> second = null;
		try {
			service = Executors.newSingleThreadExecutor();
			first = service.submit(() -> {Thread.sleep(100);return 100;});
			second = service.submit((Callable<Integer>)() -> {
				int value = 0; for (int i=0;i < 500; i++) {
//					Thread.sleep(1000);
					value +=i;
				}
				return value;
			});
		} finally {
			if (service != null) service.shutdown();
		}
		if (service != null) {
			service.awaitTermination(100, TimeUnit.MILLISECONDS);
			if (service.isTerminated()) {
				System.out.println("All services are terminated !");
				System.out.println("First =" + first.get());
				System.out.println("Second =" + second.get());
			} else {
				System.out.println("Not all services are terminated !");
			}
		}
	}

}
