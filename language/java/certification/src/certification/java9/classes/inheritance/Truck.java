package certification.java9.classes.inheritance;

public class Truck extends Vehicle {

	private int payload;

	public Truck(int payload, int weight, int power) {
		super(weight + payload, power);
		this.payload = payload;
	}

	public int getPayload() {
		return payload;
	}
}
