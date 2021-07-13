package first_spring.concert;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ AudienceResourceTest1.class, AudienceResourceTest2.class, AudienceTest.class, AudienceEncoreTest.class })
public class AllAudienceTests {

}
