package first_spring.soundsystem;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.core.env.Environment;

import first_spring.soundsystem.cdsystems.BlankDisc;
import first_spring.soundsystem.cdsystems.CompactDisc;
import first_spring.soundsystem.mediaplayers.CDPlayer;

@Configuration
@PropertySource("classpath:/configurations/envapp.properties")
public class CDplayerEvironmentConfig {

	@Autowired
	Environment env;
	
	@Bean
	public CompactDisc compactDisc() {
		return new BlankDisc(env.getProperty("disk.title"), env.getProperty("disk.author"));
	}
	
	@Bean
	public MediaPlayer mediaPlayer(CompactDisc disc) {
		return new CDPlayer(disc);
	}
}
