package certification.serialization.base;

public class Animal {

	private String name;
	private int age = 1;
	
	public Animal(final String name) {
		this.name = name;
	}
	
	public Animal() {
		this.name = "dummy";
	}
	
	public void setName(final String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	public void setAge(final int age) {
		this.age = age;
	}
	public int getAge() {
		return age;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	

}
