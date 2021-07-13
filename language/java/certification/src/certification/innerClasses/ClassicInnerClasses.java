package certification.innerClasses;

public class ClassicInnerClasses {

	private String str = "this is private";
	private class MyInner {
		private String str = "this is innerPrivate";
		public void print() {
			System.out.println("inner " + str);
			System.out.println("outer " + ClassicInnerClasses.this.str);
		}
		public void print(final Contract in) {
			in.print();
		}
	}
	public void innerPrint(){
		MyInner inner = new MyInner();
		inner.print();
		inner.print(new Contract() {
			public void print() {
				System.out.println("inner annonimous " + ClassicInnerClasses.this.str);
			}
		});
	}
	
	public Contract innerAnnonimousPrint() {
		final String strInternal = "inner annonimous";
		class Inner implements Contract{
			public void print() {
				System.out.println("Inner " + strInternal);
			}
		}
		Contract contr = new Contract() {
			public void print () {
				System.out.println("annonimous " + strInternal);
			}
		};
		contr.print();
		Inner in = new Inner();
		in.print();
		return in;
	}
	public static void main(String[] args) {
		ClassicInnerClasses outer = new ClassicInnerClasses();
		ClassicInnerClasses.MyInner inner = outer.new MyInner();
		inner.print();
		Contract annonimous = new Contract() {
			public void print() {
				System.out.println("this is annonimous");
			}
		};
		annonimous.print();
		inner.print( new Contract() { 
			public void print() {
				System.out.println("this is annonimous contract");
			}
		});
		outer.innerPrint();
		Contract innerContractMethod = outer.innerAnnonimousPrint();
		innerContractMethod.print();
	}

}
