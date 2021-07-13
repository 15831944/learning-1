package certification.serialization.collectionFieldSerializable;

import java.io.Serializable;
import java.util.List;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;

import certification.serialization.base.*;

public class Dog implements Serializable {

	private List<Prize> prizes = new ArrayList<Prize>();
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private String name;
	private int age;
	private transient int position;
	
	public Dog(final String name, final int age) {
		this.name = name;
		this.age = age;
		position = 0;
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
	
	public void addPrize(final Prize prize) {
		prizes.add(prize);
	}
	
	public List<Prize> getPrizes() {
		return prizes;
	}
	
	public Prize getNextPrize() {
		if (position < prizes.size()) {
			return prizes.get(position++);
		}
		return null;
	}
	
	public void resetPrize() {
		position = 0;
	}
	
	public void printInformation() {
		System.out.println("dog " + name + " is " + age + " years old and have :");
		for (Prize prize : prizes) {
			System.out.println("prize " + prize.getType() + " in place " + prize.getPlace());
		}
	}
	public static void main(String[] args) {
		Dog dog = new Dog("Fido", 2);
		dog.addPrize(new PrizeSerializable("beauty", 2));
		dog.addPrize(new PrizeSerializable("obedient", 3));
		dog.printInformation();
		Prize prize = dog.getNextPrize();
		System.out.println("print first prize : " + prize.getType() +  " in place " + prize.getPlace());
		
		try {
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("dogPrizes.ser"));
			os.writeObject(dog);
			os.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		try {
			ObjectInputStream is = new ObjectInputStream(new FileInputStream("dogPrizes.ser"));
			dog = (Dog) is.readObject();
			dog.printInformation();
			is.close();
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
		
		prize = dog.getNextPrize();
		System.out.println("print first prize : " + prize.getType() +  " in place " + prize.getPlace());
	}

}
