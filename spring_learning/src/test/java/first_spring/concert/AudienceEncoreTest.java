package first_spring.concert;

import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=AudienceEncoreableConfigurationResource.class)
public class AudienceEncoreTest {
	  @Rule
	  public final SystemOutRule log =
	                          new SystemOutRule().enableLog();

	  @Autowired
	  public Performance classic;
	  
	  @Autowired
	  public Encoreable encore;

	  @Test
	  public void cdShouldNotBeNull() {
	    assertNotNull(classic);
	  }

	  @Test
	  public void play() {
	    classic.perform();
	    encore.performanceEncore();
	    assertTrue(classic instanceof Encoreable);
	  }
}
