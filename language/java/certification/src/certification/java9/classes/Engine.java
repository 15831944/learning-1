package certification.java9.classes;

public class Engine {
	
	private int horsePower;
	
	public void  setHorsePower(int horsePower) {
		this.horsePower = horsePower;
	}
	
	public double getSpeedMph(double timeSec, int weightPounds) {
		double v = 2.0 * this.horsePower * 746;
		v = v*timeSec*32.17/weightPounds;
		return Math.round(Math.sqrt(v)*0.68);
	}
}
