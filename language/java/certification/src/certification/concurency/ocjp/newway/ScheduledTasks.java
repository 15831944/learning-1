package certification.concurency.ocjp.newway;

import java.util.concurrent.*;

public class ScheduledTasks {
    public static void main(String...args) {
        ScheduledExecutorService service = null;
        try {
            service = Executors.newSingleThreadScheduledExecutor();
            Runnable task1 = () -> System.out.println("Hello Zoo");
            Callable<String> task2 = () -> "Monkey";
            Future<?> result1 = service.schedule(task1, 10, TimeUnit.SECONDS);
            Future<?> result2 = service.schedule(task2, 20, TimeUnit.SECONDS);
            System.out.println(result2.get());
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
                System.out.println("At least one task is still running");
        }
    }
}
