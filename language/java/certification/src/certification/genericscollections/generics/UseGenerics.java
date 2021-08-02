package certification.genericscollections.generics;

public class UseGenerics {
    public static void main(String...args) {
        Elephant elephant = new Elephant();
        Crate<Elephant> crateForElephant = new Crate<>();
        crateForElephant.packCrate(elephant);
        Elephant eInNewHome = crateForElephant.emptyCrate();
        Zebra zebra = new Zebra();
        Crate<Zebra> crateForZebra = new Crate<>();
        crateForZebra.packCrate(zebra);
        Zebra zInNewHome = crateForZebra.emptyCrate();
    }
}
