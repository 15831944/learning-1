package certification.java9.classes.inheritance.interfaces;
/*
 * remember :
 *  static private interface method can be accessed by static and non-static methods of the same interface.
 *  non-static private interface method can be accessed only by non-static methods of the same interface.
 */
public interface Truck extends Vehicle {
	/**
     * Returns the payload of the truck.
     *
     * @return the payload of the truck in the specified units
     * of weight measurements
     * @deprecated As of API 2.1, to avoid adding methods
     * for each possible weight unit,
     * use {@link #getPayload(WeigthUnit weightUnit)} instead.
     */
	@Deprecated(since ="2.1", forRemoval= true)
	int getPayloadPounds();
	//enum WeigthUnit { Pound, Kilogram };
	/**
     * Returns the payload of the truck.
     *
     * @return the payload of the truck in the specified units
     * of weight measurements
     * @deprecated As of API 2.1, to avoid adding methods
     * for each possible weight unit,
     * use {@link #getPayload(WeigthUnit weightUnit)} instead.
     */
	@Deprecated(since ="2.1", forRemoval= true)
	default int getPayloadKg() {
		printMsg1();
		return convertPoundsToKg(getPayloadPounds());
	}
	static int convertKgToPounds(int kgs) {
		return (int) Math.round(2.205 * kgs);
	}
/*	
	default int getWeightKg(int pounds) {
		return convertPoundsToKg(pounds);
	}
*/	
	static int convertPoundsToKg(int pounds) {
		return (int) Math.round(0.454 * pounds);
	}
	private void printMsg1() {
		System.out.println("msg1 private non-static");
	}
}
