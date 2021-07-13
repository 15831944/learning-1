package certification.java9.classes.inheritance.interfaces;

import java.util.Properties;

import certification.java9.classes.inheritance.interfaces.SpeedModel.DrivingCondition;
import certification.java9.classes.inheritance.interfaces.SpeedModel.RoadCondition;
import certification.java9.classes.inheritance.interfaces.SpeedModel.TireCondition;

public class MainTestEnumsWrong {

	public static void main(String... arg) {
		double timeSec = 10.0;
		String[] roadConditions = { RoadCondition.WET.toString(), RoadCondition.SNOW.toString() };
		String[] tireConditions = { TireCondition.NEW.toString(), TireCondition.WORN.toString() };
		for (String rc : roadConditions) {
			for (String tc : tireConditions) {
				Properties drivingCond = new Properties();
				drivingCond.put(DrivingCondition.ROAD_CONDITION.toString(), rc);
				drivingCond.put(DrivingCondition.TIRE_CONDITION.toString(), tc);
				SpeedModel speedModel = FactorySpeedModel.generateSpeedModel(drivingCond);
				Car car = FactoryVehicle.buildCar(4, 4000, 246);
				car.setSpeedModel(speedModel);
				System.out.println("Car speed (" + timeSec + " sec) = " + car.getSpeedMph(timeSec) + " mph");
			}
		}
	}
}
