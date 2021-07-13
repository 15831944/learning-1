/**
 * 
 */
package certification.exceptions;

/**
 * @author gdimitriu
 *
 */
public class SuppressedExceptions implements AutoCloseable {

	private int index; 
	public void close() throws IllegalStateException {
		throw new IllegalStateException("Close exception nr:" + index);
	}
	/**
	 * 
	 */
	public SuppressedExceptions(int i) {
		this.index = i;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try (SuppressedExceptions t = new SuppressedExceptions(0); SuppressedExceptions t1 = new SuppressedExceptions(1)) {
			System.out.println("main ");
			throw new IllegalStateException("main exception");
		} catch (IllegalStateException e) {
			System.out.println("cought: " + e.getMessage());
			for (Throwable t : e.getSuppressed()) {
				System.out.println("Suppressed=" + t.getMessage());
			}
		} finally {
			System.out.println("finally");
		}
	}

}
