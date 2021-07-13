package certification.chapter2.overloadingriding;

public class Animal {

	public static void main(String[] args) {
		Animal a = new Animal();
		a.eat();
		a.test(new Integer(3), new Integer(4));
		a.test(3, 4);
		/* did not know which one should be unboxed/boxed
		a.test(new Integer(3), 4);
		*/
		a.test(new Integer(3), new Integer(4), new Integer(5));
		a.test(new Integer(3), new Integer(4), 5.5);
		a.test(new Integer(3), 4, 5);
		//a.test(new Integer(3), new Integer(5), 4);
		
	}
	public void eat() {
		System.out.println("Animal eat generic");
	}
	public void test(final int v1, final int v2) {
		System.out.println("int with int");
	}
	public void test(final Integer v1, final Integer v2) {
		System.out.println("integer with integer");
	}
	public void test(final Integer v1, final int v2, final double v3) {
		System.out.println("integer with int and int");
	}
	public void test(final Integer v1, final Object v2, final Integer v3) {
		System.out.println("Integer with object with object");
	}
	public void test(final Integer v1, final int v2, final Integer v3) {
		System.out.println("Integer with int with integer");
	}
}
