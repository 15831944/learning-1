package certification.streams.ocjp.parallel;

import java.util.ArrayList;
import java.util.List;

public class WhaleDataCalculator {
    public int processRecord(int input) {
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            // Handle interrupted exception
            e.printStackTrace();
        }
        return 1;
    }

    public long processAllData(List<Integer> data) {
        long count = 0;
        count = data.parallelStream().map(a -> processRecord(a)).mapToInt(a -> (int)a).sum();
//        count = data.stream().map(a -> processRecord(a)).mapToInt(a -> (int)a).sum();
//        for (int i = 0; i < data.size(); i++)
//            processRecord(data.get(i));
        return count;
    }

    public static void main(String[] args) {
        WhaleDataCalculator calculator = new WhaleDataCalculator();

        // Define the data
        List<Integer> data = new ArrayList<Integer>();
        for(int i=0; i<4000; i++) data.add(i);

        // Process the data
        long start = System.currentTimeMillis();
        long count = calculator.processAllData(data);
        double time = (System.currentTimeMillis()-start)/1000.0;

        // Report results
        System.out.println("\nTasks completed in: "+time+" seconds for " + count + " elements");
    }
}
