package aop.aspect;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

public class LoggingAspect {
    public void printStartLog(JoinPoint joinPoint) {
        System.out.println("------ Starting Method " + joinPoint.getSignature().getName() + " of " + joinPoint.getTarget().getClass());
    }
    public void printEndLog(JoinPoint joinPoint) {
        System.out.println("------ Ending Method " + joinPoint.getSignature().getName() + " of " + joinPoint.getTarget().getClass());
    }
    public void printAroundLog(ProceedingJoinPoint proceedingJoinPoint) throws Throwable {
        System.out.println("----- Starging of method " + proceedingJoinPoint.getSignature().getName());
        proceedingJoinPoint.proceed();
        System.out.println("----- End of method " + proceedingJoinPoint.getSignature().getName());
    }
}
