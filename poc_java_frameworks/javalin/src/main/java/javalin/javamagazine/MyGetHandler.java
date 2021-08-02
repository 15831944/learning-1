/**
 * 
 */
package javalin.javamagazine;

import io.javalin.Context;
import io.javalin.Handler;

/**
 * @author gdimitriu
 *
 */
public class MyGetHandler implements Handler {

	/**
	 * 
	 */
	public MyGetHandler() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void handle(Context ctx) throws Exception {
		ctx.result("Hello GET");
	}

}
