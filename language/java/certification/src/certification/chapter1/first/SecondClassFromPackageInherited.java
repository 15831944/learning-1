package certification.chapter1.first;
import certification.chapter1.FirstClass;

public class SecondClassFromPackageInherited extends FirstClass{

	public static void main(String[] args) {
		SecondClassFromPackageInherited a = new SecondClassFromPackageInherited();
//		System.out.println(a.var1); //does not compile
		System.out.println(a.var2);
	}
}
