package certification.java9.classes.inner;

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
		Vehicle vehicle = new Vehicle(vehicleWeight, horsePower);
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle.getSpeedMph(timeSec) + " mph");
		VehicleFullIncapsulation vehicle1 = new VehicleFullIncapsulation(vehicleWeight, horsePower);
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle1.getSpeedMph(timeSec) + " mph");
		vehicle = new Vehicle(vehicleWeight, horsePower) {
			public double getSpeedMph(double timeSec) {
				return -1.0d;
			}
		};
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle.getSpeedMph(timeSec) + " mph");
		vehicle = new Vehicle(vehicleWeight, horsePower) {
			public double getSpeedMph(double timeSec) {
//				horsePower +=10; //could not be modified because variables are final.
				double v = 2.0 * horsePower * 746;
				v = v * timeSec * 32.174 /vehicleWeight;
				return Math.round(Math.sqrt(v) * 0.68);
			}
		};
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle.getSpeedMph(timeSec) + " mph");
		VehicleInnerStatic vehicle2 = new VehicleInnerStatic(vehicleWeight, horsePower);
		System.out.println("Vehicle speed (" + timeSec + " sec)= " + vehicle2.getSpeedMph(timeSec) + " mph");

	}
}
