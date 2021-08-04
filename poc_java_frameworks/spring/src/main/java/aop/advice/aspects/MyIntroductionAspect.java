package aop.advice.aspects;

import aop.advice.dao.BookDAO_new;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.DeclareParents;

@Aspect
public class MyIntroductionAspect {
    @DeclareParents(value="aop.advice.dao.BookDAO+", defaultImpl = aop.advice.dao.BookDAO_new_Impl.class)
    BookDAO_new bookDAO_new;
}
