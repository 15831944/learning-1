package first_spring.soundsystem;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ CDplayerCollectionCountTracksTest.class, CDplayerCollectionTest.class, CDplayerTest.class,
		CDplayerTest1.class, CDplayerTest2.class, CDplayerTest3.class, CDplayerTestEnv.class })
public class AllTests {

}
