package certification.java9.classes.inheritance.first;

public class Car extends Vehicle {

	private int passengersCount;
	public Car(int passengers, int weight, int power) {
		super(weight, power);
		this.passengersCount = passengers;
	}
	
	public int getPassengersCount() {
		return this.passengersCount;
	}

	public double getSpeedMph(double timeSec) {
		int weight = this.weightPounds + this.passengersCount * 250;
/*		double v = 2.0 * this.horsePower * 746;
		v = v * timeSec * 32.174 / weight;
		return Math.round(Math.sqrt(v) * 0.68); */
		return getSpeedMph(timeSec, weight);
	}
}
