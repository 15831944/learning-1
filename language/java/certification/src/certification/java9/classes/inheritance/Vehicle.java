package certification.java9.classes.inheritance;

public class Vehicle {
	private int weightPounds;
	private int horsePower;

	public Vehicle(int weight, int power) {
		this.weightPounds = weight;
		this.horsePower = power;
	}
	
	public double getSpeedMph(double timeSec) {
		double v = 2.0 * this.horsePower * 746;
		v = v *timeSec * 32.174/this.weightPounds;
		return Math.round(Math.sqrt(v)*0.68);
	}
}
