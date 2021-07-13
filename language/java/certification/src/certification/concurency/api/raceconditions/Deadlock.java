package certification.concurency.api.raceconditions;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Deadlock {

	public static void main(String[] args) {
		//create participants and resources
		Fox foxy = new Fox("foxy");
		Fox tails = new Fox("tails");
		Food food = new Food();
		Water water = new Water();
		
		//process data
		ExecutorService service = null;
		try {
			service = Executors.newScheduledThreadPool(10);
			service.submit(() -> foxy.eatAndDrink(food, water));
			service.submit(() -> tails.drinkAndEat(food, water));
		} finally {
			if (service != null) {
				service.shutdown();
			}
		}
	}

}

class Food {}
class Water {}

class Fox {
	private String name;
	public Fox(final String name) {
		this.name = name;
	}
	public void eatAndDrink(Food food, Water water) {
		synchronized(food) {
			System.out.println(name + " Got food");
			move();
			synchronized(water) {
				System.out.println(name + " Got water");
			}
		}
	}
	public void drinkAndEat(Food food, Water water) {
		synchronized(water) {
			System.out.println(name + " Got water");
			move();
			synchronized(food) {
				System.out.println(name + "Get food");
			}
		}
	}
	public void move() {
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			
		}
	}
}