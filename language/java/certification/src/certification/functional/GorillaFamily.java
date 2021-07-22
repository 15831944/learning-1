package functional;
interface Gorilla {
    String move();
}
public class GorillaFamily {
    String walk = "walk";
    void everyonePlay(boolean baby) {
        String approach = "amble";
        //approach = "run"; //this will make approach not efective finally so lambda will fail to compile
        play(() -> walk);
        play(() -> baby ? "hitch a ride" : "run");
        play(() -> approach);
    }

    void play(Gorilla g) {
        System.out.println(g.move());
    }
    public static void main(String...args) {
        GorillaFamily family = new GorillaFamily();
        family.everyonePlay(true);
    }
}
