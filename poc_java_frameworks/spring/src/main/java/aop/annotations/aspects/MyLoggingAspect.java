package aop.annotations.aspects;

import org.apache.log4j.Logger;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;

@Aspect
public class MyLoggingAspect {
    Logger logger = Logger.getLogger(getClass());

    @Pointcut(value="execution(* aop.annotations.dao.BookDAO.addBook(aop.annotations.beans.Book))")
    public void selectAdd() { }

    @Pointcut(value="execution(* aop.annotations.dao.BookDAO.*(..))")
    public void selectAll() { }

    @Before(value="selectAdd()")
    public void beforeAdvise(JoinPoint joinPoint) {
        logger.info("method will be invoked " + joinPoint.getSignature());
    }

    @After(value="selectAll()")
    public void afterAdvise(JoinPoint joinPoint) {
        logger.info("method has been invoked successfully" + joinPoint.getSignature());
    }

    @AfterThrowing(pointcut = "selectAll()", throwing = "exception")
    public void throwingAdvise(JoinPoint joinPoint, Exception exception) {
        logger.error(joinPoint.getSignature() + " got an exception \t" + exception.toString());
    }

    @AfterReturning(pointcut = "selectAll()", returning = "val")
    public void returnAdvise(JoinPoint joinPoint, Object val) {
        logger.info(joinPoint.getSignature() + " returning value " + val);
    }

    @Around("selectAdd()")
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
}
