/* TestArithmetic.java
	exemplu de utilizaare a operatorilor aritmetici
*/
import java.util.*;
public class TestArithmetic
{
	public static void main(String args[])
	{
		testInteger();
		testFloat();
	}
	public static void testInteger()
	{
		int op1,op2;
		Random randGen=new Random();	//se obtin 2 numere intregi in mod aleator
		op1=randGen.nextInt();
		op2=randGen.nextInt();
		System.out.println("\n Test Integer:");
		
		System.out.println("op1="+op1+";"+"op2="+op2+";");
		System.out.println("op1+op2="+op1+"+"+op2+"="+(op1+op2)+";");
		System.out.println("op1-op2="+op1+"-"+op2+"="+(op1-op2)+";"+"op2-op1="+op2+"-"+op1+"="+(op2-op1)+";");
		System.out.println("op1*op2="+op1+"*"+op2+"="+(op1*op2)+";");
		System.out.println("op1/op2="+op1+"/"+op2+"="+(op1/op2)+";"+"op2/op1="+op2+"/"+op1+"="+(op2/op1)+";");
		System.out.println("op1%op2="+op1+"%"+op2+"="+(op1%op2)+";"+"op2%op1="+op2+"%"+op1+"="+(op2%op1)+";");
		System.out.println("op1="+op1+";"+"-op1="+(-op1));
		System.out.println("op1="+op1+";"+"+op1="+(+op1));
		System.out.println("op1="+op1+";"+"op1++="+(op1++));
		System.out.println("op1="+op1+";"+"++op1="+(++op1));
		System.out.println("op1="+op1+";"+"op1--="+(op1--));
		System.out.println("op1="+op1+";"+"--op1="+(--op1));
	}
	public static void testFloat()
	{
		float op1,op2;
		Random randGen=new Random();	//se obtin 2 numere float in mod aleator
		op1=randGen.nextFloat();
		op2=randGen.nextFloat();
		System.out.println("\n Test Float:");
		
		System.out.println("op1="+op1+";"+"op2="+op2+";");
		System.out.println("op1+op2="+op1+"+"+op2+"="+(op1+op2)+";");
		System.out.println("op1-op2="+op1+"-"+op2+"="+(op1-op2)+";"+"op2-op1="+op2+"-"+op1+"="+(op2-op1)+";");
		System.out.println("op1*op2="+op1+"*"+op2+"="+(op1*op2)+";");
		System.out.println("op1/op2="+op1+"/"+op2+"="+(op1/op2)+";"+"op2/op1="+op2+"/"+op1+"="+(op2/op1)+";");
		System.out.println("op1%op2="+op1+"%"+op2+"="+(op1%op2)+";"+"op2%op1="+op2+"%"+op1+"="+(op2%op1)+";");
		System.out.println("op1="+op1+";"+"-op1="+(-op1));
		System.out.println("op1="+op1+";"+"+op1="+(+op1));
		System.out.println("op1="+op1+";"+"op1++="+(op1++));
		System.out.println("op1="+op1+";"+"++op1="+(++op1));
		System.out.println("op1="+op1+";"+"op1--="+(op1--));
		System.out.println("op1="+op1+";"+"--op1="+(--op1));
	}
}