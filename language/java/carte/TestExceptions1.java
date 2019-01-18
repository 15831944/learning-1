/*
	Din nou lucrul cu try-catch-finally
*/
import java.io.*;
public class TestExceptions1
{
	public static void main(String args[])
	{
		for(int i=0;i<=4;i++)
		{
			try
			{
				System.out.println("\r\nCazul i= "+i);
				method1(i);
			}
			catch(Exception e)
			{
				System.out.println("S-a prins in main exception:");
				e.printStackTrace(System.out);
			}
			catch(Throwable e)
			{
				System.out.println("S-a prins in main Throwable:");
				e.printStackTrace(System.out);
			}
			finally
			{
				System.out.println("Executie finally in main");
			}
		}
	}
	private static void method1(int i) throws Throwable
	{
		try
		{
			System.out.println("\t Start method1");
			method2(i);
			System.out.println("\t End method1");
			return;
		}
		catch(Exception e)
		{
			System.out.println("\t S-a prins Exception in method1:"+e.getMessage());
			switch(i)
			{
				case 1: System.out.println("\t Return din method1");
						return;
				case 2:System.out.println("\t Method1 arunca o noua exceptie");
						throw new Exception("Exceptie din method1");
				case 3:System.out.println("\t Method1 paseaza exceptia"+" mai departe emodificata");
						throw e;
				case 4:System.out.println("\t Method1 paseaza eceptia mai departe modificind stiva");
						throw e.fillInStackTrace();
			}
		}
		finally
		{
			System.out.println("\t Executie finally in method1");
		}
	}
	private static void method2(int i) throws Exception
	{
		System.out.println("\t\t Start method2;");
		if(i!=0)
		{
			System.out.println("\t\t Method 2 arunca exceptie;");
			throw new Exception("Exceptie din method2");
		}
		System.out.println("\t\t End method2;");
	}
}