package certification.java9.classes.inheritance.interfaces;

import java.util.Properties;

public class MainTest {

	public MainTest() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String... arg) {
		double timeSec = 10.0;
		int horsePower = 246;
		int vehicleWeight = 4000;
		Properties drivingConditions = new Properties();
		drivingConditions.put("roadCondition", "Wet");
		drivingConditions.put("tireCondition", "New");
		SpeedModel speedModel = FactorySpeedModel.generateSpeedModel(drivingConditions);
		Car car = FactoryVehicle.buildCar(4, vehicleWeight, horsePower);
		car.setSpeedModel(speedModel);
		System.out.println("Car speed (" + timeSec + " sec) = " + car.getSpeedMph(timeSec) + " mph");
		
		Vehicle vehicle = FactoryVehicle.buildCrewCab(4, 3300, vehicleWeight, horsePower);
		vehicle.setSpeedModel(speedModel);
		System.out.println("Payload = " + ((Truck)vehicle).getPayloadPounds() + " pounds");				
		System.out.println("Payload = " + ((Truck)vehicle).getPayloadKg() + " Kg");
		int kg = ((Truck)vehicle).getPayloadKg();
		System.out.println("Payload converted back to pounds =" + Truck.convertKgToPounds(kg));
//		System.out.println("Weight converted to Kg = " + ((Truck)vehicle).getWeightKg(vehicleWeight));
		System.out.println("Weight converted to Kg using static= " + Truck.convertPoundsToKg(vehicleWeight));
		System.out.println("Passengers = " + ((Car)vehicle).getPassengersCount() + " passengers");
		System.out.println("Crew cab speed " + timeSec + " sec) = " + vehicle.getSpeedMph(timeSec) + " mph");
		
	}
}
