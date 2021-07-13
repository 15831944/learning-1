package first_spring.soundsystem;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.contrib.java.lang.system.SystemOutRule;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import first_spring.soundsystem.cdsystems.CompactDisc;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=CDplayerEvironmentConfig.class)
public class CDplayerTestEnv {
	  @Rule
	  public final SystemOutRule log =
	                          new SystemOutRule().enableLog();

	  @Autowired
	  private MediaPlayer player;

	  @Autowired
	  private CompactDisc cd;

	  @Test
	  public void cdShouldNotBeNull() {
	    assertNotNull(cd);
	  }

	  @Test
	  public void play() {
	    player.play();
	    assertEquals(
	        "Playing Sgt. Pepper's Lonely Hearts Club Band by The Beatles\n",
	        log.getLogWithNormalizedLineSeparator());
	  }
}
