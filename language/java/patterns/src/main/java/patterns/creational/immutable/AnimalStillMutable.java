package patterns.creational.immutable;

import java.util.ArrayList;
import java.util.List;

public final class AnimalStillMutable {
    private final List<String> favoriteFoods;

    public AnimalStillMutable(List<String> favoriteFoods) {
        if (favoriteFoods == null) {
            throw new RuntimeException("FavoriteFoods is required");
        }
        this.favoriteFoods = new ArrayList<>(favoriteFoods);
    }

    public List<String> getFavoriteFoods() { // MAKE class MUTABLE AGAIN !!!
        return favoriteFoods;
    }
}
