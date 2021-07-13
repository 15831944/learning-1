package first_spring.soundsystem;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import first_spring.soundsystem.cdsystems.CompactDisc;
import first_spring.soundsystem.cdsystems.SgtPeppers;
import first_spring.soundsystem.mediaplayers.CDPlayer;

@Configuration
public class CDplayerConfigBean {

	@Bean
	public CompactDisc stgPeppers() {
		return new SgtPeppers();
	}
/*	
	@Bean
	public MediaPlayer mediaPlayer() {
		return new CDPlayer(stgPeppers());
	}
*/
	@Bean
	public MediaPlayer mediaPlayer(CompactDisc disc) {
		return new CDPlayer(disc);
	}
}
