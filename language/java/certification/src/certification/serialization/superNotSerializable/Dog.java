package certification.serialization.superNotSerializable;

import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.Serializable;

import certification.serialization.base.Animal;

public class Dog extends Animal implements Serializable{

	public Dog(final String name, final int age) {
		super(name);
		setAge(age);
	}
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public static void main(String[] args) {
		Dog dog = new Dog("Fido", 5);
		try {
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("dog.ser"));
			os.writeObject(dog);
			os.flush();
			os.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		printDogObject(dog);
		
		try {
			ObjectInputStream is = new ObjectInputStream(new FileInputStream("dog.ser"));
			printDogObject((Dog) is.readObject());
			is.close();
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static void printDogObject(final Dog dog) {
		System.out.println("dog name = " + dog.getName() + " has " + dog.getAge() + " years old.");
	}
	
	private void writeObject(ObjectOutputStream os) {
		try {
			os.defaultWriteObject();
			os.writeObject(getName());
			os.writeInt(getAge());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void readObject(ObjectInputStream is) {
		try {
			is.defaultReadObject();
			setName((String) is.readObject());
			setAge(is.readInt());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
