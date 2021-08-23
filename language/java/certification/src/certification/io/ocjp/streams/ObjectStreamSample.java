package certification.io.ocjp.streams;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class ObjectStreamSample {
    public static List<Animal> getAnimals(File dataFile) throws IOException, ClassNotFoundException {
        List<Animal> animals = new ArrayList<>();
        try(ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(dataFile)))) {
            while(true) {
                Object object = in.readObject();
                if (object instanceof Animal)
                    animals.add((Animal)object);
            }
        } catch (EOFException e) {
            //file end reached
        }
        return animals;
    }

    public static void createAnimalsFile(List<Animal> animals, File dataFile) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(dataFile)))) {
            for (Animal animal : animals)
                out.writeObject(animal);
        }
    }

    public static void main(String...args) throws IOException, ClassNotFoundException {
        if (args.length != 1) {
            System.out.println("Call with fileName");
            System.exit(-1);
        }
        List<Animal> animals = new ArrayList<>();
        animals.add(new Animal("Tommy Tiger", 5 , 'T'));
        animals.add(new Animal("Peter Penguin",8, 'P'));
        File dataFile = new File(args[0]);
        createAnimalsFile(animals,dataFile);
        System.out.println(getAnimals(dataFile));
    }
}
