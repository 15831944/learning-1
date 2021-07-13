package certification.java9.classes.inheritance.interfaces;

import java.util.Properties;

public class FactorySpeedModel {

	private static FactorySpeedModel singleton = new FactorySpeedModel();
	
	public static SpeedModel generateSpeedModel(Properties drivingConditions) {
		String road = drivingConditions.getProperty("ROAD_CONDITION", "DRY");
		if (road.equals("DRY")) {
			return singleton.new SpeedModelDry();
		}
		if (road.equals("WET")) {
			return singleton.new SpeedModelWet();
		}
		return singleton.new SpeedModelDry();
	}
	
	private class SpeedModelWet implements SpeedModel {

		@Override
		public double getSpeedMph(double timeSec, int weightPounds, int horsePower) {
			double v = 2.0 * horsePower * 746;
			v = v * timeSec * 32.174 / weightPounds;
			return Math.round(Math.sqrt(v) * 0.68) - 5;
		}
		
	}
	
	private class SpeedModelDry implements SpeedModel {

		@Override
		public double getSpeedMph(double timeSec, int weightPounds, int horsePower) {
			double v = 2.0 * horsePower * 746;
			v = v * timeSec * 32.174 / weightPounds;
			return Math.round(Math.sqrt(v) * 0.68) - 2;
		}
		
	}
}
