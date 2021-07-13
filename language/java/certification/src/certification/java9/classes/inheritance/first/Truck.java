package certification.java9.classes.inheritance.first;

public class Truck extends Vehicle {

	private int payload;

	public Truck(int payload, int weight, int power) {
		super(weight, power);
		this.payload = payload;
	}

	public int getPayload() {
		return payload;
	}

	public double getSpeedMph(double timeSec) {
		int weight = this.weightPounds + this.payload;
/*		double v = 2.0 * this.horsePower * 746;
		v = v * timeSec * 32.174 / weight;
		return Math.round(Math.sqrt(v) * 0.68); */
		return getSpeedMph(timeSec, weight);
	}
}
