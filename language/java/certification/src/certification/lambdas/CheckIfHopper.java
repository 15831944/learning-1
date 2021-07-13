/**
 * 
 */
package certification.lambdas;

/**
 * @author Gabriel
 *
 */
public class CheckIfHopper implements CheckTrait {

	/* (non-Javadoc)
	 * @see certification.lambdas.CheckTrait#test(certification.lambdas.Animal)
	 */
	@Override
	public boolean test(Animal a) {
		return a.canHop();
	}

}
