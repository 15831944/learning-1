/**
 * 
 */
package first_spring.concert;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.DeclareParents;

/**
 * @author Gabriel
 *
 */
@Aspect
public class EncoreableIntroducer {
	
	@DeclareParents( value ="first_spring.concert.Performance+", defaultImpl=DefaultEncoreable.class)
	public static Encoreable encoreable;

}
