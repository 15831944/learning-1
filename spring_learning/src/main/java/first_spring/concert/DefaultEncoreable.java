/**
 * 
 */
package first_spring.concert;

/**
 * @author Gabriel
 *
 */
public class DefaultEncoreable implements Encoreable {

	/* (non-Javadoc)
	 * @see first_spring.concert.Encoreable#performanceEncore()
	 */
	@Override
	public void performanceEncore() {
		System.out.println("Perform once again");
	}

}
