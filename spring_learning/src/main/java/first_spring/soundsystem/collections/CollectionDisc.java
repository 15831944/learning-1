package first_spring.soundsystem.collections;

import java.util.List;

import first_spring.soundsystem.cdsystems.CompactDisc;

public class CollectionDisc implements CompactDisc {

	private String title;
	private String artist;
	private List<String> tracks;
	
	public CollectionDisc() {
		tracks = null;
	}
	
	public CollectionDisc(String title, String artist, List<String> tracks) {
		this.title = title;
		this.artist = artist;
		this.tracks = tracks;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}

	public void setArtist(String artist) {
		this.artist = artist;
	}

	public void setTracks(List<String> tracks) {
		this.tracks = tracks;
	}
	
	
	public void play() {
		System.out.println("Playing " + title + " by " + artist);
	    for (String track : tracks) {
	      System.out.println("-Track: " + track);
	    }
	}
	
	@Override
	public void playTrack(int trackNumber) {
		if (trackNumber > tracks.size()) {
			return;
		}
		System.out.println("Playing " + title + " by " + artist);
		System.out.println("-Track: " + tracks.get(trackNumber));
	}

}
