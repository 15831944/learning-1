package certification.java9.classes.inheritance.interfaces;

import certification.java9.classes.inheritance.interfaces.SpeedModel.RoadCondition;
import certification.java9.classes.inheritance.interfaces.SpeedModel.TireCondition;

public class MainTestEnums {

	public static void main(String... arg) {
		double timeSec = 10.0;
		for (RoadCondition road : RoadCondition.values()) {
			for (TireCondition tire: TireCondition.values()) {
				road.temperature = 63;
				SpeedModel speedModel = FactorySpeedModelEnums.generateSpeedModel(road, tire);
				Car car = FactoryVehicle.buildCar(4, 4000, 246);
				car.setSpeedModel(speedModel);
				System.out.println("Car speed (" + timeSec + " sec) = " + car.getSpeedMph(timeSec) + " mph");
			}
		}
	}
}
