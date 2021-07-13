package first_spring.concert;

import static org.junit.Assert.assertNotNull;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=AudienceConfigurationResource.class)
public class AudienceResourceTest1 {
	  @Rule
	  public final SystemOutRule log =
	                          new SystemOutRule().enableLog();

	  @Autowired
	  public Performance classic;

	  @Test
	  public void cdShouldNotBeNull() {
	    assertNotNull(classic);
	  }

	  @Test
	  public void play() {
	    classic.perform();
	  }
}
