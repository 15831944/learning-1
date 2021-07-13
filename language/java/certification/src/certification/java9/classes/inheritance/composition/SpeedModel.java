package certification.java9.classes.inheritance.composition;

import java.util.Properties;

public class SpeedModel {
	private Properties drivingConditions;
	
	public SpeedModel(Properties drivingConditions) {
		this.drivingConditions = drivingConditions;
	}
	
	public double getSpeedMph(double timeSec, int weightPounds, int horsePower) {
		String road = drivingConditions.getProperty("roadCondition", "Dry");
		String tire = drivingConditions.getProperty("tirecondition", "New");
		double v = 2.0 * horsePower * 746;
		v = v * timeSec * 32.174 /weightPounds;
		return Math.round(Math.sqrt(v) * 0.68)
				- (road.equals("Dry") ? 2 : 5)
				- (tire.equals("New") ? 0 : 5);
	}
}
