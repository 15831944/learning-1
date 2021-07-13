package certification.chapter2.constructors;

public class Horse extends Animal {

	private static String type;
	
	public Horse(final String name) {
		super(name);
	}
	
	Horse() {
		
	}
	
	public String Horse() {
		return "Horse is horse";
	}
	
	public void eats() {
		System.out.println("Horse eats hay");
	}
	
	public static String getType() {
		return type;
	}
	
	public static void setType(final String type) {
		Horse.type = type;
	}
	public static void main(final String[] args) {
		Animal.setType("the animal");
		Animal an = new Animal("Zeus");
		System.out.println(an.getName());
		an.eats();
		Horse horse = new Horse("Zeus");
		System.out.println(horse.getName());
		horse.eats();
		an = new Horse("Marghioala");
		an.eats();
		System.out.println(Animal.getType());
		Horse.setType("armasar");
		System.out.println(Horse.getType());
		System.out.println(((Horse) an).Horse());
	}
}
