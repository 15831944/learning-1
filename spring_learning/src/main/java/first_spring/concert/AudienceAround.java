/**
 * 
 */
package first_spring.concert;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;

/**
 * @author Gabriel
 *
 */
@Aspect
public class AudienceAround {

	@Pointcut("execution(* first_spring.concert.Performance.perform(..))")
	void performance() {}
	
	@Around("performance()")
	public void watchPerformance(ProceedingJoinPoint jp) {
		try {
			System.out.println("Please silence you mobile phones !");
			System.out.println("Please take you seats !");
			jp.proceed();
			System.out.println("Aplause !");
		} catch (Throwable e) {
			System.out.println("Demanding refund !");
		}
	}
}
