package certification.java9.classes.inheritance.second;

public class Car extends Vehicle {

	private int passengersCount;
	public Car(int passengers, int weight, int power) {
		super(weight, power);
		this.passengersCount = passengers;
	}
	
	public int getPassengersCount() {
		return this.passengersCount;
	}

	public int getMaxWeightPounds() {
		return this.weightPounds + this.passengersCount * 250;
	}
}
