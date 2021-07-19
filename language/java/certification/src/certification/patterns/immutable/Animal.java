package patterns.immutable;

import java.util.ArrayList;
import java.util.List;

public class Animal {
    private final List<String> favoriteFoods;
    public Animal(List<String> favoriteFoods) {
        if (favoriteFoods == null)
            throw new RuntimeException("Favorite foods is required");
        this.favoriteFoods = new ArrayList<>(favoriteFoods);
    }

    public List<String> getFavoriteFoods() { //make this class mutable
        return favoriteFoods;
    }
}
