package certification.concurency.ocjp.newway;

import java.util.concurrent.*;

public class AddData {
    public static void main(String...args) {
        ExecutorService service = null;
        try {
            service = Executors.newSingleThreadExecutor();
            Future<Integer> result = service.submit(() -> 30+11);
            System.out.println(result.get());
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            if (service != null)
                service.shutdown();
        }
        if (service != null) {
            try {
                service.awaitTermination(1, TimeUnit.MINUTES);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if (service.isTerminated())
                System.out.println("All tasks finished");
            else
                System.out.println("At least one task is running");
        }
    }
}
