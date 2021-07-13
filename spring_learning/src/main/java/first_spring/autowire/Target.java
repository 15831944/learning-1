/**
 * 
 */
package first_spring.autowire;

import org.springframework.context.support.GenericXmlApplicationContext;

/**
 * @author Gabriel Dimitriu
 *
 */
public class Target {
	private Foo foo;
	private Foo foo2;
	private Bar bar;
	
	public Target() {
		
	}
	public Target(final Foo foo) {
		System.out.println("Target(Foo) called");
	}
	public Target(final Foo foo, final Bar bar) {
		System.out.println("Traget(Foo,Bar) called");
	}
	public Foo getFoo() {
		return foo;
	}
	public void setFoo(Foo foo) {
		this.foo = foo;
		System.out.println("Property foo set");
	}
	public Foo getFoo2() {
		return foo2;
	}
	public void setFoo2(Foo foo2) {
		this.foo2 = foo2;
		System.out.println("Property foo2 set");
	}
	public Bar getBar() {
		return bar;
	}
	public void setBar(Bar bar) {
		this.bar = bar;
		System.out.println("Property bar set");
	}
	
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("autowirecontext.xml");
		ctx.refresh();
		Target t = null;
		System.out.println("Using byName:\n");
		t = (Target) ctx.getBean("targetByName");
		System.out.println("Using byType: \n");
		t = (Target) ctx.getBean("targetByType");
		System.out.println("Using constructor:\n");
		t = (Target) ctx.getBean("targetConstructor");
	}
}
