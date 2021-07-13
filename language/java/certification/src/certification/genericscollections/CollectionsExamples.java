/**
 * 
 */
package certification.genericscollections;

import java.util.Arrays;
import java.util.List;

/**
 * @author Gabriel Dimitriu
 *
 */
public class CollectionsExamples {

	/**
	 * 
	 */
	public CollectionsExamples() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List<String> list = Arrays.asList("a","b","c");
		for (String str : list) {
			System.out.println(str);
		}
		try {
			list.remove(1);
		} catch (UnsupportedOperationException e) {
			System.out.println("Tried to remove from array not from list");
		}
	}

}
