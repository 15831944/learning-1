/**
 * 
 */
package first_spring.soundsystem.collections;

import java.util.HashMap;
import java.util.Map;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

/**
 * @author Gabriel
 *
 */
@Aspect
public class TrackCounter {
	private Map<Integer, Integer> tracksCount = new HashMap<>();
	
	@Pointcut("execution(* first_spring.soundsystem.cdsystems.CompactDisc.playTrack(int)) " + 
	"&& args(trackNumber)")
	public void trackPlayed(int trackNumber) {
	}
	
	@Before("trackPlayed(trackNumber)")
	public void countTrack(int trackNumber) {
		int currentCount = getPlayCount(trackNumber);
		tracksCount.put(trackNumber, currentCount + 1);
	}
	
	public int getPlayCount(int trackNumber) {
		return tracksCount.getOrDefault(trackNumber, 0);
	}
}
