package certification.genericscollections.generics;

/*
 * E is for element
 * K for map key
 * V for map value
 * N for a number
 * T for generic data
 * S,U,V for multiple generic types
 *
 */
public class Crate<T> {
    private T contents;
    public T emptyCrate() {
        return contents;
    }
    public void packCrate(T contents) {
        this.contents = contents;
    }
}
