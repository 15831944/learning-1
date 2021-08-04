package aop.xmlbased.aspects;

import org.apache.log4j.Logger;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

public class MyLoggingAspect {
    Logger logger = Logger.getLogger(getClass());
    public void beforeAdvise(JoinPoint joinPoint) {
        logger.info("method will be invoked: - " + joinPoint.getSignature());
    }
    public void afterAdvise(JoinPoint joinPoint) {
        logger.info("executed successfully: - " + joinPoint.getSignature());
    }
    public void returnAdvise(JoinPoint joinPoint, Object val) {
        logger.info(joinPoint.getSignature() + " returning value=" + val);
    }

    public int aroundAdvise(ProceedingJoinPoint joinPoint) {
        long start_time = System.currentTimeMillis();
        logger.info("around advise before " + joinPoint.getSignature() + " before method been called");
        Integer o = null;
        try {
            o = (Integer)joinPoint.proceed();
            logger.info("number of rows affected " + o);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        logger.info("around advise after " + joinPoint.getSignature() + " after method been called");
        long end_time = System.currentTimeMillis();
        logger.info(joinPoint.getSignature() + " took " + (end_time-start_time) + " ms to complete");
        return o.intValue();
    }
    public void throwingAdvise(JoinPoint joinPoint, Exception exception) {
        logger.error(joinPoint.getSignature() + " got the exception " + "\t" + exception.toString());
    }
}
