package certification.java9.classes;

public class Vehicle {

	private int weightPounds;
	private Engine engine;
	
	/**
	 * 
	 */
	public Vehicle(int weight, Engine engine) {
		this.weightPounds = weight;
		this.engine = engine;
	}

	public double getSpeedMph(double timeSec) {
		if(engine == null) {
			throw new RuntimeException("Engine is required parameter!");
		}
		return this.engine.getSpeedMph(timeSec, weightPounds);
	}
}
