/**
 * 
 */
package first_spring.initmethod;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.BeanCreationException;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

/**
 * @author Gabriel Dimitriu
 *
 */
public class SimpleBeanWithJSR250 {

	private static final String DEFAULT_NAME = "Luke Skywalker";
	private String name;
	private int age = Integer.MAX_VALUE;
	
	
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

	@PostConstruct
	public void init() {
		System.out.println("Initializing bean");
		if (name == null) {
			System.out.println("Using default name");
			name = DEFAULT_NAME;
		}
		if (age == Integer.MAX_VALUE) {
			throw new IllegalArgumentException("You must set the age property of any beans of type:" + SimpleBeanWithJSR250.class);
		}
	}
	
	public String toString() {
		return "Name: " + name + "\nAge: " + age;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		ctx.load("initmethodwithjsr250.xml");
		ctx.refresh();
		
		SimpleBeanWithJSR250 simpleBean1 = getBean("simpleBean1", ctx);
		SimpleBeanWithJSR250 simpleBean2 = getBean("simpleBean2", ctx);
		SimpleBeanWithJSR250 simpleBean3 = getBean("simpleBean3", ctx);
		ctx.close();
	}

	private static SimpleBeanWithJSR250 getBean(final String beanName, final ApplicationContext ctx) {
		try {
			SimpleBeanWithJSR250 bean = (SimpleBeanWithJSR250) ctx.getBean(beanName);
			System.out.println(bean);
			return bean;
		} catch (BeanCreationException ex) {
			System.out.println("An error occured in bean configuration: " + ex.getMessage());
			return null;
		}
	}
}
