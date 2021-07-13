/**
 * 
 */
package first_spring.concert;

import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

/**
 * @author gdimitriu
 *
 */
@Aspect
public class Audience2 {

	@Pointcut("execution(* first_spring.concert.Performance.perform(..))")
	public void performance() {}
	
	@Before("performance()")
	public void silenceYourPhones() {
		System.out.println("Silence your phones please!");
	}
	
	@Before("performance()")
	public void takeYourSeats() {
		System.out.println("Take your seats please !");
	}
	
	@AfterReturning("performance()")
	public void aplause() {
		System.out.println("Aplause !!!");
	}
	
	@AfterThrowing("performance()")
	public void demandRefund() {
		System.out.println("Demand refund !");
	}
}
