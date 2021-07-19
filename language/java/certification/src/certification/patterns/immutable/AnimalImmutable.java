package patterns.immutable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AnimalImmutable {
    private final List<String> favoriteFoods;
    private final String species;
    private final int age;
    public AnimalImmutable(String species, int age, List<String> favoriteFoods) {
        this.species = species;
        this.age = age;
        if (favoriteFoods == null)
            throw new RuntimeException("Favorite foods is required");
        this.favoriteFoods = new ArrayList<>(favoriteFoods);
    }

    public List<String> getFavoriteFoods() { //this is not recommended because break the 5 rules
        return Collections.unmodifiableList(favoriteFoods);
    }

    public String getSpecies() {
        return species;
    }

    public int getAge() {
        return age;
    }

    public int getFavoriteFoodCount() {
        return favoriteFoods.size();
    }

    public String getFavoriteFood(int index) {
        return favoriteFoods.get(index);
    }

    @Override
    public String toString() {
        return "Animal: of " + species + " of age " + age + " has favorite foods " + favoriteFoods;
    }
}
