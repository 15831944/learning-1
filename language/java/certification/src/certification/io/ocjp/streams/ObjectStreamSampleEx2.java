package certification.io.ocjp.streams;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class ObjectStreamSampleEx2 {
    public static List<AnimalEx2> getAnimals(File dataFile) throws IOException, ClassNotFoundException {
        List<AnimalEx2> animals = new ArrayList<>();
        try(ObjectInputStream in = new ObjectInputStream(new BufferedInputStream(new FileInputStream(dataFile)))) {
            while(true) {
                Object object = in.readObject();
                if (object instanceof AnimalEx2)
                    animals.add((AnimalEx2)object);
            }
        } catch (EOFException e) {
            //file end reached
        }
        return animals;
    }

    public static void createAnimalsFile(List<AnimalEx2> animals, File dataFile) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(dataFile)))) {
            for (AnimalEx2 animal : animals)
                out.writeObject(animal);
        }
    }

    public static void main(String...args) throws IOException, ClassNotFoundException {
        if (args.length != 1) {
            System.out.println("Call with fileName");
            System.exit(-1);
        }
        List<AnimalEx2> animals = new ArrayList<>();
        animals.add(new AnimalEx2("Tommy Tiger", 5 , 'T'));
        animals.add(new AnimalEx2("Peter Penguin",8, 'P'));
        File dataFile = new File(args[0]);
        createAnimalsFile(animals,dataFile);
        System.out.println(getAnimals(dataFile));
    }
}
