package certification.concurency.api;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class AddDataExecutors {

	public AddDataExecutors() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws InterruptedException, ExecutionException {
		ExecutorService service = null;
		try {
			service = Executors.newSingleThreadExecutor();
			Future<Integer> result = service.submit(() -> { return 20+10;});
			System.out.println(result.get());
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
