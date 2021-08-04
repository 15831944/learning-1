package certification.patterns.builders;

import patterns.immutable.AnimalImmutable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class UsingBuilder {
    public static void main(String...args) {
        AnimalBuilder builder = new AnimalBuilder();
        builder.setSpecies("lion").setAge(5).setFavoriteFoods(Arrays.asList("meat", "more meat"));
        AnimalImmutable lion = builder.build();
        List<String> favoriteFoods = new ArrayList<>();
        for(int i = 0; i < lion.getFavoriteFoodCount(); i++)
            favoriteFoods.add(lion.getFavoriteFood(i));
        AnimalImmutable updateLion = new AnimalImmutable(lion.getSpecies(), lion.getAge() +1 , favoriteFoods);
        System.out.println(lion);
        System.out.println(updateLion);
        AnimalBuilder duckBuilder = new AnimalBuilder();
        duckBuilder
                .setAge(4)
                .setFavoriteFoods(Arrays.asList("grass","fish")).setSpecies("duck");
        AnimalImmutable duck = duckBuilder.build();

        AnimalImmutable flamingo = new AnimalBuilder()
                .setFavoriteFoods(Arrays.asList("algae","insects"))
                .setSpecies("flamingo").build();

        System.out.println(duck);
        System.out.println(flamingo);
    }
}
