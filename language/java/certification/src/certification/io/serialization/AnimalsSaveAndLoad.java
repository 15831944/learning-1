/**
 * 
 */
package certification.io.serialization;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Gabriel Dimitriu
 *
 */
public class AnimalsSaveAndLoad {

	/**
	 * 
	 */
	public AnimalsSaveAndLoad() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		AnimalsSaveAndLoad saveLoader = new AnimalsSaveAndLoad();
		List<Animal> animals = new ArrayList<>();
		animals.add(new Animal("Teo", "Tom", 2));
		animals.add(new Animal("Pinky", "Gaby", 5));
		animals.add(new Animal("FatCat", "FatMan", 2));
		File saved = new File("d:\\tmp\\animals.dat");
		try {
			saveLoader.saveAnimals(animals, saved);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
		try {
			System.out.println(saveLoader.loadAnimals(saved));
		} catch (ClassNotFoundException | IOException e) {
			e.printStackTrace();
		}
		saved.delete();
	}

	public void saveAnimals(List<Animal> animals, File dataFile) throws FileNotFoundException, IOException {
		try(ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(dataFile)))) {
			for (Animal animal : animals) {
				out.writeObject(animal);
			}
		}
	}
	
	public List<Animal> loadAnimals(final File dataFile) throws FileNotFoundException, IOException, ClassNotFoundException {
		List<Animal> animals = new ArrayList<>();
		try (ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(dataFile)))) {
			while(true) {
				Object obj = in.readObject();
				if (obj instanceof Animal) {
					animals.add((Animal) obj);
				}
			}
		} catch (EOFException e) {
			//nothing to do just break the while
		}
		return animals;
	}
}
