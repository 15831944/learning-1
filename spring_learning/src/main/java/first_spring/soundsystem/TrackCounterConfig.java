/**
 * 
 */
package first_spring.soundsystem;

import java.util.ArrayList;
import java.util.List;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

import first_spring.soundsystem.cdsystems.CompactDisc;
import first_spring.soundsystem.collections.CollectionDisc;
import first_spring.soundsystem.collections.TrackCounter;

/**
 * @author Gabriel
 *
 */
@Configuration
@EnableAspectJAutoProxy
public class TrackCounterConfig {
	
	@Bean
	public CompactDisc sgtPepers() {
		CollectionDisc cd = new CollectionDisc();
		cd.setTitle("Sgt. Peppers's Lonely Hearts Club Band");
		cd.setArtist("The Beatles");
		List<String> tracks = new ArrayList<>();
		tracks.add("Sgt. Peppers's Lonely Hearts Club Band");
		tracks.add("With a Little Help from My Friends");
		tracks.add("Lucy in the Sky with Diamonds");
		tracks.add("Getting Better");
		tracks.add("Fixing the holde");
		cd.setTracks(tracks);
		return cd;
	}
	
	@Bean
	public TrackCounter trackCounter() {
		return new TrackCounter();
	}

}
