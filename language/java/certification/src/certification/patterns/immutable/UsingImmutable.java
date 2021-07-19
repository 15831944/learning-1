package patterns.immutable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class UsingImmutable {
    public static void main(String...args) {
        AnimalImmutable lion = new AnimalImmutable("lion",5, Arrays.asList("meat","more meat"));
        List<String> favoriteFoods = new ArrayList<>();
        for(int i = 0; i < lion.getFavoriteFoodCount(); i++)
            favoriteFoods.add(lion.getFavoriteFood(i));
        AnimalImmutable updateLion = new AnimalImmutable(lion.getSpecies(), lion.getAge() +1 , favoriteFoods);
        System.out.println(lion);
        System.out.println(updateLion);
    }
}
