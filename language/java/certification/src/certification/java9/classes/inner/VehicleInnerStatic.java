package certification.java9.classes.inner;

public class VehicleInnerStatic {
	
	
	private Engine engine;
	/**
	 * 
	 */
	public VehicleInnerStatic(int weight, int power) {
		this.engine = new Engine(weight, power);
	}

	public double getSpeedMph(double timeSec) {
		return this.engine.getSpeedMph(timeSec);
	}

	private static class Engine
	{
		private int weightPounds;
		private int horsePower;
		private Engine(int weight, int power) {
			this.horsePower = power;
			this.weightPounds = weight;
		}
		private double getSpeedMph(double timeSec) {
			double v = 2.0 *this.horsePower * 746;
			v = v * timeSec * 32.174 /weightPounds;
			return Math.round(Math.sqrt(v) * 0.68);
		}
	}
}
