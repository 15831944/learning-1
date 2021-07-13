package certification.java9.classes.inheritance.second;

public abstract class Vehicle {
	protected int weightPounds;
	protected int horsePower;

	public Vehicle(int weight, int power) {
		this.weightPounds = weight;
		this.horsePower = power;
	}
	
	public double getSpeedMph(double timeSec) {
		double v = 2.0 * this.horsePower * 746;
		v = v *timeSec * 32.174/getMaxWeightPounds();
		return Math.round(Math.sqrt(v)*0.68);
	}

	public abstract int getMaxWeightPounds();
}
