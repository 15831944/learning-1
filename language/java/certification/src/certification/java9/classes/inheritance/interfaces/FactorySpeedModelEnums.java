package certification.java9.classes.inheritance.interfaces;

import certification.java9.classes.inheritance.interfaces.SpeedModel.RoadCondition;
import certification.java9.classes.inheritance.interfaces.SpeedModel.TireCondition;

public class FactorySpeedModelEnums {

	private static FactorySpeedModelEnums singleton = new FactorySpeedModelEnums();
	
	public static SpeedModel generateSpeedModel(RoadCondition road, TireCondition tire) {
		return singleton.new SpeedModelImpl(road, tire);
	}
	
	private class SpeedModelImpl implements SpeedModel {
		private RoadCondition road;
		private TireCondition tire;
		SpeedModelImpl(RoadCondition road, TireCondition tire) {
			this.road = road;
			this.tire = tire;
		}
		@Override
		public double getSpeedMph(double timeSec, int weightPounds, int horsePower) {
			System.out.println("Road contion is " + road.name() + " => traction=" + road.getTraction());
			System.out.println("Tire contion is " + tire.name() + " => traction=" + tire.getTraction());
			double v = 2.0 * horsePower * 746;
			v = v * timeSec * 32.174 / weightPounds;
			v = v * road.getTraction()*tire.getTraction();
			return Math.round(Math.sqrt(v) * 0.68);
		}
		
	}
}
