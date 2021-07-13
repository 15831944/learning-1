package certification.concurency.api;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class CheckingResultsExecutors {

	public static int counter = 0;
	
	public CheckingResultsExecutors() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws InterruptedException, ExecutionException {
		ExecutorService service = null;
		try {
			service = Executors.newSingleThreadExecutor();
			Future<?> result =service.submit(() -> {
				for (int i = 0 ;i < 50000; i++) {
					CheckingResultsExecutors.counter++;
				}
			});
			result.get(10, TimeUnit.MILLISECONDS);
			System.out.println("Reached!");
		}
		catch (TimeoutException e) {
			System.out.println("Not reached yet !");
		}
		finally {
			if (service != null) service.shutdown();
		}
	}

}
