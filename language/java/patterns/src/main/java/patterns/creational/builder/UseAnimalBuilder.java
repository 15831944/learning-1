package patterns.creational.builder;

import patterns.creational.immutable.Animal;

import java.util.Arrays;

public class UseAnimalBuilder {
    public static void main(String...args) {
        //create an Animal instance
        Animal lion =  new AnimalBuilder().setSpecies("lion").setAge(4)
                .setFavoriteFoods( Arrays.asList("meat", "more meat")).build();

        AnimalBuilder duckBuilder = new AnimalBuilder();
        duckBuilder.setAge(4).setFavoriteFoods(Arrays.asList("grass", "fish")).setSpecies("duck");
        Animal duck = duckBuilder.build();

        Animal flamingo = new AnimalBuilder().setAge(2).setSpecies("flamingo")
                .setFavoriteFoods(Arrays.asList("algae", "insects")).build();
    }
}
