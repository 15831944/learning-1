/**
 * 
 */
package first_spring.initmethod;

import org.springframework.beans.factory.BeanCreationException;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

/**
 * @author Gabriel Dimitriu
 *
 */
public class SimpleBean {

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

	public void init() {
		System.out.println("Initializing bean");
		if (name == null) {
			System.out.println("Using default name");
			name = DEFAULT_NAME;
		}
		if (age == Integer.MAX_VALUE) {
			throw new IllegalArgumentException("You must set the age property of any beans of type:" + SimpleBean.class);
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
		ctx.load("initmethod.xml");
		ctx.refresh();
		
		SimpleBean simpleBean1 = getBean("simpleBean1", ctx);
		SimpleBean simpleBean2 = getBean("simpleBean2", ctx);
		SimpleBean simpleBean3 = getBean("simpleBean3", ctx);
		ctx.close();
	}

	private static SimpleBean getBean(final String beanName, final ApplicationContext ctx) {
		try {
			SimpleBean bean = (SimpleBean) ctx.getBean(beanName);
			System.out.println(bean);
			return bean;
		} catch (BeanCreationException ex) {
			System.out.println("An error occured in bean configuration: " + ex.getMessage());
			return null;
		}
	}
}
