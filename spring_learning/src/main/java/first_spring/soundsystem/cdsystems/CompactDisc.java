package first_spring.soundsystem.cdsystems;

public interface CompactDisc {
	  void play();
	  
	  default void playTrack(int trackNumber) {
		  System.out.println("there is no tracks here");
	  }
}