package certification.java9.classes.inheritance.second;

public class Truck extends Vehicle {

	private int payload;

	public Truck(int payload, int weight, int power) {
		super(weight, power);
		this.payload = payload;
	}

	public int getPayload() {
		return payload;
	}

	public int getMaxWeightPounds() {
		return this.weightPounds + this.payload;
	}
}
