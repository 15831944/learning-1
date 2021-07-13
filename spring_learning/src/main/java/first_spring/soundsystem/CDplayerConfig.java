package first_spring.soundsystem;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan(basePackages = {"first_spring.soundsystem.cdsystems", "first_spring.soundsystem.mediaplayers"})
//@ComponentScan(basePackageClasses = {CompactDisc.class, MediaPlayer.class})
public class CDplayerConfig {

}
