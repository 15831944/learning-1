package certification.java9.classes.inner;

public class VehicleFullIncapsulation {
	
	private int weightPounds;
	private int horsePower;
	/**
	 * 
	 */
	public VehicleFullIncapsulation(int weight, int power) {
		this.weightPounds = weight;
		this.horsePower = power;
	}

	public double getSpeedMph(double timeSec) {
		class Engine
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
		Engine engine = new Engine(this.horsePower);
		return engine.getSpeedMph(timeSec);
	}

	private int getWeighPounds() {
		return weightPounds;
	}
}
