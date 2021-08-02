package certification.genericscollections.generics;

import java.util.ArrayList;
import java.util.List;
interface Fly {

}
class Bird implements  Fly{

}

class Sparrow extends Bird {

}
public class ArraysWildcard {
    public static void main(String...args) {
        List<? extends Bird> birds = new ArrayList<>();
//        birds.add(new Bird()); //does not compile
//        birds.add(new Sparrow()); //does not compile

        List<? extends Fly> birds1 = new ArrayList<>();
//        birds1.add(new Bird()); //does not compile
//        birds1.add(new Sparrow()); //does not compile
    }
}
