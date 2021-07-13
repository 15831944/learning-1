package first_spring.soundsystem;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import first_spring.soundsystem.cdsystems.CompactDisc;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=CDplayerConfig.class)
public class CDplayerTest {

  @Autowired
  private CompactDisc cd;
  
  private CompactDisc cd1;
  
  @Autowired
  public void setSecondCompactDisk(CompactDisc cd) {
	  this.cd1 = cd;
  }

  @Test
  public void cdShouldNotBeNull() {
    assertNotNull(cd);
    assertNotNull(cd1);
  }

}