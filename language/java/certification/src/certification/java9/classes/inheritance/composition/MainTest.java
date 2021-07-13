package certification.java9.classes.inheritance.composition;

import java.util.Properties;

public class MainTest {

	public MainTest() {
		// TODO Auto-generated constructor stub
	}
	
	public static void main(String... arg) {
		  double timeSec = 10.0;
		  int engineHorsePower = 246;
		  int vehicleWeightPounds = 4000;
		  Properties drivingConditions = new Properties();
		  drivingConditions.put("roadCondition", "Wet");
		  drivingConditions.put("tireCondition", "New");
		  SpeedModel speedModel = new SpeedModel(drivingConditions);
		  Vehicle vehicle = new Car(4, vehicleWeightPounds, engineHorsePower);		  
		  vehicle.setSpeedModel(speedModel);
		  System.out.println("Passengers count=" + 
		                     ((Car)vehicle).getPassengersCount());
		  System.out.println("Car speed (" + timeSec + " sec) = " + 
		                     vehicle.getSpeedMph(timeSec) + " mph");
		  vehicle = new Truck(3300, vehicleWeightPounds, engineHorsePower);
		  vehicle.setSpeedModel(speedModel);
		  System.out.println("Payload=" + 
		                     ((Truck)vehicle).getPayload() + " pounds");
		  System.out.println("Truck speed (" + timeSec + " sec) = " + 
		                     vehicle.getSpeedMph(timeSec) + " mph");
		}
}
