package certification.java9.classes.inheritance.first;

public class Vehicle {
	protected int weightPounds;
	protected int horsePower;

	public Vehicle(int weight, int power) {
		this.weightPounds = weight;
		this.horsePower = power;
	}
	
	public double getSpeedMph(double timeSec) {
		double v = 2.0 * this.horsePower * 746;
		v = v *timeSec * 32.174/this.weightPounds;
		return Math.round(Math.sqrt(v)*0.68);
	}

	protected double getSpeedMph(double timeSec, int weightPounds) {
		double v = 2.0 * this.horsePower * 746;
		v = v *timeSec * 32.174/weightPounds;
		return Math.round(Math.sqrt(v)*0.68);
	}
}
