/**
 * 
 */
package certification.genericscollections;

import java.util.ArrayList;
import java.util.List;

/**
 * @author gdimitriu
 *
 */

class Bird{};

class Sparrow extends Bird{};

public class AssignGeneric {

	public static void acceptList(List<? extends Bird> val) {
		
	}
	
	public static void acceptListBird(List<Bird> val) {
		
	}
	/**
	 * 
	 */
	public AssignGeneric() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List<Bird> birds = new ArrayList<>();
		birds.add(new Sparrow());
		birds.add(new Bird());
		List<Sparrow> sparrows = new ArrayList<>();
		sparrows.add(new Sparrow());
		AssignGeneric.acceptList(birds);
		AssignGeneric.acceptListBird(birds);
		AssignGeneric.acceptList(sparrows);
//		AssignGeneric.acceptListBird(sparrows);
//		List<? extends Bird> birds = new ArrayList<Sparrow>();
//		birds.add(new Sparrow());
//		birds.add(new Bird());
	}

}
