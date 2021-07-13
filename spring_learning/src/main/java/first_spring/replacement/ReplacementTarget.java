/**
 * 
 */
package first_spring.replacement;

/**
 * @author Gabriel Dimitriu
 *
 */
public class ReplacementTarget {
	public String formatMessage(String msg) {
		return "<h1>" + msg + "</h1>";
	}
	
	public String formatMessage(Object msg) {
		return "<h1>" + msg + "</h1>";
	}
}
