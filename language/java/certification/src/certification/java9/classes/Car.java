package certification.java9.classes;

public class Car extends Vehicle {

	private int passengersCount;
	/**
	 * @param weight
	 * @param engine
	 */
	public Car(int passengers, int weight, Engine engine) {
		super(weight, engine);
		this.passengersCount = passengers;
	}
	public int getPassengersCount() {
		return passengersCount;
	}

}
