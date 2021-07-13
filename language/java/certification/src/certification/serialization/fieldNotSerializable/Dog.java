package certification.serialization.fieldNotSerializable;

import java.io.IOException;
import java.io.Serializable;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.FileOutputStream;
import java.io.FileInputStream;

import certification.serialization.base.Prize;

public class Dog implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private transient Prize prize = null;
	private String name = null;
	private int age = 0;
	private transient int actualPosition;
	
	public Dog(final String name, final int age, final Prize prize) {
		this.name = name;
		this.age = age;
		this.prize = prize;
	}
	
	public Dog() {
		this.name = "dummy";
		this.age = 0;
		this.prize = new Prize("none", 0);
	}
	
	public Prize getPrize() {
		return prize;
	}
	
	public void setPrize(final Prize prize) {
		this.prize = prize;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(final String name) {
		this.name = name;
	}
	
	public void setAge(final int age) {
		this.age = age;
	}
	
	public int getAge() {
		return age;
	}
	
	public int getActualPosition() {
		return actualPosition;
	}
	
	public void setActualPosition(final int position) {
		actualPosition = position;
	}
	
	private void writeObject(ObjectOutputStream os) {
		try {
			os.defaultWriteObject();
			os.writeObject(name);
			os.writeInt(age);
			os.writeObject(prize.getType());
			os.writeInt(prize.getPlace());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void readObject(ObjectInputStream is) {
		try {
			is.defaultReadObject();
			name = (String) is.readObject();
			age = is.readInt();
			prize = new Prize((String) is.readObject(), is.readInt());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void printInformation() {
		System.out.println("dog " + name + " is " + age 
				+ " years old and has prize " + prize.getType() + " at place " + prize.getPlace()
				+ " and has actual position " + actualPosition);
	}

	public static void main(String[] args) {
		Prize prize = new Prize("Beauty", 3);
		Dog dog  = new Dog("Fido", 2, prize);
		dog.setActualPosition(-1);
		dog.printInformation();
		
		try {
			FileOutputStream fos = new FileOutputStream("dogPrize.ser");
			ObjectOutputStream os = new ObjectOutputStream(fos);
			os.writeObject(dog);
			os.flush();
			os.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			FileInputStream fis = new FileInputStream("dogPrize.ser");
			ObjectInputStream is = new ObjectInputStream(fis);
			dog = (Dog) is.readObject();
			dog.printInformation();
			is.close();
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

}
