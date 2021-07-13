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
import first_spring.soundsystem.collections.TrackCounter;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=TrackCounterConfig.class)
public class CDplayerCollectionCountTracksTest {
	  @Rule
	  public final SystemOutRule log =
	                          new SystemOutRule().enableLog();
	  @Autowired
	  private CompactDisc cd;
	  
	  @Autowired
	  private TrackCounter counter;

	  @Test
	  public void cdShouldNotBeNull() {
	    assertNotNull(cd);
	  }

	  @Test
	  public void testTrackCounter() {
		  cd.playTrack(0);
		  cd.playTrack(1);
		  cd.playTrack(2);
		  cd.playTrack(2);
		  cd.playTrack(2);
		  cd.playTrack(2);
		  cd.playTrack(4);
		  cd.playTrack(4);
		  assertEquals(1, counter.getPlayCount(0));
		  assertEquals(1, counter.getPlayCount(1));
		  assertEquals(4, counter.getPlayCount(2));
		  assertEquals(0, counter.getPlayCount(3));
		  assertEquals(2, counter.getPlayCount(4));
		  assertEquals(0, counter.getPlayCount(5));
	  }
}
