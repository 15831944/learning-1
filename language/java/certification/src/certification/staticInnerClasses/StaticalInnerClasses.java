package certification.staticInnerClasses;

import certification.innerClasses.Contract;

public class StaticalInnerClasses {

	private static String staticStr = "this is static outer str";
	private String str = "this is not statical str";
	public static class MyStaticalInner {
		private String strInner = "this is not statical inner str";
		public static void print() {
			System.out.println("this is statical inner class");
			System.out.println("inner " + staticStr);
		}
		public static void print ( final Contract in) {
			in.print();
		}
		public void printNotStatic () {
//			System.out.println("inner not static" + str);
			System.out.println("inner not static " + strInner);
		}
	}
	public static void main(String[] args) {
		StaticalInnerClasses.MyStaticalInner.print();
		StaticalInnerClasses.MyStaticalInner.print( new Contract() {
			public void print () {
				System.out.println("this is the contract");
			}
		});
		StaticalInnerClasses.MyStaticalInner st = new StaticalInnerClasses.MyStaticalInner();
		st.printNotStatic();
	}

}
