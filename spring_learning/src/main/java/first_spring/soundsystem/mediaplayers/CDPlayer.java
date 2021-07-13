package first_spring.soundsystem.mediaplayers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import first_spring.soundsystem.MediaPlayer;
import first_spring.soundsystem.cdsystems.CompactDisc;

@Component
public class CDPlayer implements MediaPlayer {
	
	CompactDisc cd;
	
	@Autowired
	public CDPlayer(CompactDisc cd) {
		this.cd = cd;
	}

	public void play() {
		cd.play();
	}

}
