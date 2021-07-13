/**
 * 
 */
package first_spring.concert;

import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;

/**
 * @author gdimitriu
 *
 */
@Aspect
public class Audience1 {

	@Before("execution(* first_spring.concert.Performance.perform(..))")
	public void silenceYourPhones() {
		System.out.println("Silence your phones please!");
	}
	
	@Before("execution(* first_spring.concert.Performance.perform(..))")
	public void takeYourSeats() {
		System.out.println("Take your seats please !");
	}
	
	@AfterReturning("execution(* first_spring.concert.Performance.perform(..))")
	public void aplause() {
		System.out.println("Aplause !!!");
	}
	
	@AfterThrowing("execution(* first_spring.concert.Performance.perform(..))")
	public void demandRefund() {
		System.out.println("Demand refund !");
	}
}
