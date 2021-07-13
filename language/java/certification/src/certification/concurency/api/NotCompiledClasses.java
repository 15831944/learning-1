package certification.concurency.api;

import java.io.IOException;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.function.Supplier;

public class NotCompiledClasses {

	public NotCompiledClasses() {
		// TODO Auto-generated constructor stub
	}

	static void use(Supplier<Integer> suplier) {}
	static void use(Callable<Integer> callable) {}
	public static void main(String[] args) {
		//use(() -> {throw new IOException();}); //does not compile ambigous
		use((Callable<Integer>)() -> {throw new IOException();});
		ExecutorService service = null;
		try {
			service = Executors.newSingleThreadExecutor();
			service.submit(() -> { 
				Thread.sleep(1000);
				return null;
				}); 
			//service.submit(() -> {Thread.sleep(1000);}); //doesnot compile without try internally
		} finally {
			if (service != null) service.shutdown();
		}
	}

}
