package certification.java9.classes.inner;

public class Vehicle {
	
	private int weightPounds;
	private Engine engine;
	/**
	 * 
	 */
	public Vehicle(int weight, int power) {
		this.weightPounds = weight;
		this.engine = new Engine(power);
	}

	public double getSpeedMph(double timeSec) {
		return this.engine.getSpeedMph(timeSec);
	}

	private int getWeighPounds() {
		return weightPounds;
	}
	private class Engine
	{
		private int horsePower;
		private Engine(int power) {
			this.horsePower = power;
		}
		private double getSpeedMph(double timeSec) {
			double v = 2.0 *this.horsePower * 746;
			v = v * timeSec * 32.174 /getWeighPounds();
			return Math.round(Math.sqrt(v) * 0.68);
		}
	}
}
