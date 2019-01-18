/* TestBitOperations.java
	Exemplu de testare operatori binari
*/
public class TestBitOperations
{
	public static void main(String args[])
	{
		int int1=11;//8+2+1
		int int2=-11;
		int rez;
		
		System.out.println("int1= \t"+int1+"\t="+getBinary(int1));
		System.out.println("int2= \t"+int2+"\t="+getBinary(int2));
		System.out.println("~int1= \t"+~int1+"\t="+getBinary(~int1));
		System.out.println("~int2= \t"+~int2+"\t="+getBinary(~int2));
		rez=int1&int2;
		System.out.println("int1&int2= \t"+rez+"\t="+getBinary(rez));
		rez=int1|int2;
		System.out.println("int1|int2= \t"+rez+"\t="+getBinary(rez));
		rez=int1^int2;
		System.out.println("int1^int2= \t"+rez+"\t="+getBinary(rez));
		rez=int1<<3;
		System.out.println("int1<<3= \t"+rez+"\t="+getBinary(rez));
		rez=int2<<3;
		System.out.println("int2<<3= \t"+rez+"\t="+getBinary(rez));
		rez=int1>>3;
		System.out.println("int1>>3= \t"+rez+"\t="+getBinary(rez));
		rez=int2>>3;
		System.out.println("int2>>3= \t"+rez+"\t="+getBinary(rez));
		rez=int1>>>3;
		System.out.println("int1>>>3= \t"+rez+"\t="+getBinary(rez));
		rez=int2>>>3;
		System.out.println("int2>>>3= \t"+rez+"\t="+getBinary(rez));
	}
	public static String getBinary(int val)
	{
		StringBuffer bin=new StringBuffer("");
		for(int i=31;i>=0;i--)
		{
			if(((1<<i)&val) !=0) bin.append("1");
			else bin.append("0");
		}
		bin.append("b");
		return bin.toString();
	}
}