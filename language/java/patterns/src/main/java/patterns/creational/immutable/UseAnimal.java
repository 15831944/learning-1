package patterns.creational.immutable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class UseAnimal {
    public static void main(String...args) {
        //create an Animal instance
        Animal lion = new Animal("lion", 4, Arrays.asList("meat", "more meat"));
        // create a new Animal instance using data from the first instance
        List<String> favoriteFoods = new ArrayList<>();
        for(int i = 0; i < lion.getFavoriteFavoriteFoodsCount(); i++) {
            favoriteFoods.add(lion.getFavoriteFood(i));
        }
        Animal updatedLion = new Animal(lion.getSpecies(), lion.getAge() + 1, favoriteFoods);
    }
}
