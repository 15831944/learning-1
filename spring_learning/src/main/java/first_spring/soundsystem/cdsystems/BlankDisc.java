/**
 * 
 */
package first_spring.soundsystem.cdsystems;

/**
 * @author gdimitriu
 *
 */
public class BlankDisc implements CompactDisc {

	private String title;
	private String artist;
	
	public BlankDisc(String title, String artist) {
		this.title = title;
		this.artist = artist;
	}
	/* (non-Javadoc)
	 * @see first_spring.soundsystem.cdsystems.CompactDisc#play()
	 */
	public void play() {
		System.out.println("Playing " + title + " by " + artist);
	}
}
