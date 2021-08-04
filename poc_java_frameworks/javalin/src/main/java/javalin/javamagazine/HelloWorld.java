/**
 * 
 */
package javalin.javamagazine;

import io.javalin.Javalin;

/**
 * @author gdimitriu
 *
 */
public class HelloWorld {

	/**
	 * 
	 */
	public HelloWorld() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Javalin app = Javalin.create().start(7000);
		app.get("/", ctx -> ctx.result("Hello World"));
		app.get("/hello-get", new MyGetHandler());
	}

}
