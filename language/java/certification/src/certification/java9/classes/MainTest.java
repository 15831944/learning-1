package certification.java9.classes;

public class MainTest {

	/**
	 * 
	 */
	public MainTest() {
		// TODO Auto-generated constructor stub
	}
	
	public static void main(String... arg) {
		double timeSec = 10.0;
		int horsePower = 246;
		int vehicleWeight = 4000;
		Engine engine = new Engine();
		engine.setHorsePower(horsePower);
		Vehicle vehicle = new Vehicle(vehicleWeight, engine);
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle.getSpeedMph(timeSec) + " mph");
		vehicle = new Car(4, vehicleWeight, engine);
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle.getSpeedMph(timeSec) + " mph");
		
	}
}
