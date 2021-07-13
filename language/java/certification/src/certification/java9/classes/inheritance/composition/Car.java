package certification.java9.classes.inheritance.composition;

public class Car extends Vehicle {

	private int passengersCount;
	public Car(int passengers, int weight, int power) {
		super(weight + passengers * 250, power);
		this.passengersCount = passengers;
	}
	
	public int getPassengersCount() {
		return this.passengersCount;
	}
}
