/**
 * 
 */
package certification.lambdas;

/**
 * @author Gabriel
 *
 */
public class Animal {
	private String species;
	private boolean canHop;
	private boolean canSwim;
	public Animal(final String species, final boolean canhop, final boolean canswim) {
		this.species = species;
		this.canHop = canhop;
		this.canSwim = canswim;
	}
	
	public boolean canHop() {
		return canHop;
	}
	
	public boolean canSwim() {
		return canSwim;
	}
	
	public String toString() {
		return species;
	}
}
