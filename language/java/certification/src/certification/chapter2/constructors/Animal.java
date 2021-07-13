package certification.chapter2.constructors;

public class Animal {
	private String name;
	private static String type;
	
	public Animal() {
		name = "withoutName";
	}
	public Animal(final String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public void setName(final String name) {
		this.name = name;
	}
	public void eats() {
		System.out.println("animal eats");
	}
	
	public static void setType(final String type) {
		Animal.type = type;
	}
	
	public static String getType() {
		return Animal.type;
	}
}
