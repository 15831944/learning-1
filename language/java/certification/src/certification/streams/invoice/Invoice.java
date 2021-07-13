/**
 * 
 */
package certification.streams.invoice;

/**
 * @author Gabriel
 *
 */
public class Invoice {

	private double ammount;
	private String contributor;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public Invoice(final String contributor, final double ammount) {
		this.contributor = contributor;
		this.ammount = ammount;
	}
	
	public Invoice() {
		
	}

	public double getAmmount() {
		return ammount;
	}
	
	public void setAmmount(final double inAmmount) {
		ammount = inAmmount;
	}
	
	public void setContributor(final String inContributor) {
		contributor = inContributor;
	}
	
	public String getContributor() {
		return contributor;
	}
}
