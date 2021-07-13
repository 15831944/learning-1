package certification.concurency.api.parallelstream;

import java.util.ArrayList;
import java.util.List;

public class WhaleDataCalculator {

	public int processingRecord(int input) {
		try {
			Thread.sleep(10);			
		} catch (InterruptedException e) {
			
		}
		return input + 1;
	}
	
	public void processingAllData(List<Integer> data) {
		data.stream().map(a -> processingRecord(a)).count();
	}
	
	public void processingAllDataParallel(List<Integer> data) {
		data.parallelStream().map( a -> processingRecord(a)).count();
	}
	
	public static void main(String[] args) {
		WhaleDataCalculator calculator = new WhaleDataCalculator();
		//define the data
		List<Integer> data = new ArrayList<>();
		for(int i = 0; i < 4000; i++) data.add(i);
		
		//process the data
		long start = System.currentTimeMillis();
		calculator.processingAllData(data);
		double time = (System.currentTimeMillis() - start)/1000.0;
		//report results
		System.out.println("\n Serial task completed in : "+ time + " seconds");
		//process the data
		start = System.currentTimeMillis();
		calculator.processingAllDataParallel(data);
		time = (System.currentTimeMillis() - start)/1000.0;
		//report results
		System.out.println("\n Parallel task completed in : "+ time + " seconds");
				
	}

}
