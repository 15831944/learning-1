/* TestCast.java
	Exemplificare cast
*/
import java.util.*;
public class TestCast
{
	public static void main(String args[])
	{
		testCast();
	}
	public static void testCast()
	{
		Random gen=new Random();
		byte opByte=(byte)gen.nextInt();
		short opShort=(short)gen.nextInt();
		char opChar=(char)gen.nextInt();
		int opInt=gen.nextInt();
		long opLong=gen.nextInt();
		
		float opFloat=gen.nextFloat();
		double opDouble=gen.nextFloat();
		
		int rezInt;
		float rezFloat;
		
		rezInt=opByte/opShort;	//rezultatul e un int deoarece si byte si short trec la int inainte de operatatie
		rezFloat=opByte/opShort;
		System.out.print("byte/short \t");
		System.out.println("rez="+opByte+"/"+opShort+"="+rezInt+"="+rezFloat);
		rezInt=opInt/opShort;//opShort este tranformat in int deci rez este int
		rezFloat=opInt/opShort;
		System.out.print("int/short \t");
		System.out.println("rez="+opInt+"/"+opShort+"="+rezInt+"="+rezFloat);
		rezInt=(int)(opLong/opChar);
		rezFloat=opLong/opChar;
		System.out.print("long/char \t");
		System.out.println("rez="+opLong+"/"+opChar+"="+rezInt+"="+rezFloat);
		rezInt=(int)(opFloat/opInt);
		rezFloat=opFloat/opInt;
		System.out.print("float/int \t");
		System.out.println("rez="+opFloat+"/"+opInt+"="+rezInt+"="+rezFloat);
		rezInt=(int)(opDouble/opFloat);
		rezFloat=(float)(opDouble/opFloat);
		System.out.print("double/float \t");
		System.out.println("rez="+opDouble+"/"+opFloat+"="+rezInt+"="+rezFloat);
	}
}