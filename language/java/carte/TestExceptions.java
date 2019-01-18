/* 
	Lucrul cu try-catch-finaly
*/
import java.io.*;
public class TestExceptions
{
	public static void main(String args[])
	{
		for(int i=0;i<=1;i++)
		{
			try
			{
				System.out.println("\n Test case "+i);
				method1(i);
				System.out.println("End test case "+i);
			}
			catch(Exception e)
			{
				System.out.println("A aparut o exceptie:"+e.getMessage());
			}
			finally
			{
				System.out.println("Inside finally");
			}
		}
	}
	private static void method1(int i) throws Exception
	{
		System.out.println("Begin method1;");
		if(i!=0) throw new Exception("Din method1");
		System.out.println("End method1;");
	}
}