/**
 * 
 */
package certification.streams;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.*;
import certification.streams.invoice.Invoice;
import java.util.Comparator;
/**
 * @author Gabriel
 *
 */
public class ContributorInvoices {
	private List<Invoice> contributors;
	
	public ContributorInvoices() {
		contributors = new ArrayList<Invoice>();
		for (int i = 0; i < 10; i++) {
			contributors.add(new Invoice("Buru" + i, i*1000.0));
		}
	}
		
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ContributorInvoices invoices = new ContributorInvoices();
		invoices.bigger3000Sorted();
		invoices.reduced();
	}


	public void bigger3000Sorted() {
		List<String> rez = contributors.stream().filter(inv -> inv.getAmmount() > 3000.0)
				.sorted(Comparator.comparingDouble(Invoice::getAmmount))
				.map(Invoice::getContributor).collect(Collectors.toList());
		System.out.println("Normal comparator");
		for(String str : rez) {
			System.out.println(str);
		}
		rez = contributors.stream().filter(inv -> inv.getAmmount() > 3000.0)
				.sorted(new Comparator<Invoice>() {
					@Override
					public int compare(Invoice o1, Invoice o2) {
						return Double.compare(o2.getAmmount(), o1.getAmmount());
					}
				})
				.map(Invoice::getContributor).collect(Collectors.toList());
		System.out.println("reverse comparator");
		for(String str : rez) {
			System.out.println(str);
		}
	}

	public void reduced() {
		System.out.println("sum of all values lower than 4000 is=" +
				contributors.stream().filter(inv -> inv.getAmmount() < 4000)
				.map(Invoice::getAmmount).reduce(0.0, (inv1, inv2) -> inv1 + inv2)
			);
	}
}
