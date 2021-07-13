/**
 * 
 */
package certification.io.serialization;

import java.io.Serializable;

/**
 * @author Gabriel Dimitriu
 *
 */
public class Animal implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String name;
	private String owner;
	private int age;

	/**
	 * 
	 */
	public Animal() {
		// TODO Auto-generated constructor stub
	}
	
	public Animal(final String name, final String owner, final int age) {
		this.name = name;
		this.owner = owner;
		this.age = age;
	}

	public void setName(final String name) {
		this.name = name;
	}
	
	public void setOwner(final String owner) {
		this.owner = owner;
	}
	
	public void setAge(final int age) {
		this.age = age;
	}
	
	public String getName() {
		return name;
	}
	
	public String getOwner() {
		return owner;
	}
	
	public int getAge() {
		return age;
	}
	
	public String toString() {
		return "Animal :" + name + " has owner :" + owner + " has age " + age;
	}
}
