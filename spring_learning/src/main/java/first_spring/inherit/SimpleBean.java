/**
 * 
 */
package first_spring.inherit;

import org.springframework.context.support.GenericXmlApplicationContext;

/**
 * @author Gabriel Dimitriu
 *
 */
public class SimpleBean {

	private String name;
	private int age;
	
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("inheritbean.xml");
		ctx.refresh();
		SimpleBean parent = (SimpleBean) ctx.getBean("inheritParent");
		SimpleBean child = (SimpleBean) ctx.getBean("inheritChild");
		System.out.println("Parent:\n" + parent);
		System.out.println("Child:\n" + child);
		ctx.close();
	}

	/**
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * @param age the age to set
	 */
	public void setAge(int age) {
		this.age = age;
	}
	
	public String toString() {
		return "Name: " + name + "\n" + "Age: "  + age;
	}
}
