package aop.aspect;

import org.aspectj.lang.JoinPoint;

public class SendMessage {
    public void sendMessageOnSuccessExit(JoinPoint joinPoint) {
        System.out.println(" ----  Method " + joinPoint.getSignature().getName() + " of "
                + joinPoint.getTarget().getClass() + " is successfully");
    }

    public String sendMessageOnSuccessExitWithData(JoinPoint joinPoint, String retVal) {
        System.out.println(" ----  Method " + joinPoint.getSignature().getName() + " of "
                + joinPoint.getTarget().getClass() + " is successfully");
        System.out.println(" The return value is --> " + retVal);
        return "Successfully exited with return val is -->" + retVal;
    }

    public void setMessageOnExceptionExit(JoinPoint joinPoint) {
        System.out.println(" ---- Method " + joinPoint.getSignature().getName() + " of "
        + joinPoint.getTarget().getClass() +  " has thrown exception");
    }
}
