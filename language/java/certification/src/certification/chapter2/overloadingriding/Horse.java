package certification.chapter2.overloadingriding;

public class Horse extends Animal {

	public static void main(String[] args) {
		Animal a = new Animal();
		a.eat();
		a = new Horse();
		a.eat();
		Horse h = new Horse();
		h.eat();
		//a.eat("treats");
		h.eat("treats");
	}
	public void eat() {
		System.out.println("Horse eats hay");
	}
	public void eat(final String what) {
		System.out.println("Horse eats " + what);
	}
/* could not reduce visibility	
	private void eat() {
		System.out.println("error");
	}
*/
/* could not throws new exceptions which are not declared by super method
	public void eat() throws Exception {
		throw new Exception("bla");
	}
*/
}
