/*
	Exemplu de testare a fucntiilor oferite de clasa Throwable
*/
public class TestThrowableMethods
{
	public static void main(String args[])
	{
		for(int i=0;i<=1;i++)
		{
			System.out.println("\nCazul "+i);
			try
			{
				method1(i);
			}
			catch(Throwable e)
			{
				System.out.println("Main: Oare ce-am primit ?");
				System.out.println("getmessage()="+e.getMessage());
				System.out.println("toString="+e.toString());
				System.out.println("printStackTrace=");
				e.printStackTrace();	//echivalenta metodei e.printStackTrace(System.out);
			}
		}
	}
	private static void method1(int caz) throws Throwable
	{
		try
		{
			method2();
		}
		catch(Throwable e)
		{
			System.out.println("method1=metoda securist a primit mesajul");
			if(caz==0)
			{
				System.out.println("Libera trecere");
				throw e;
			}else
			{
				System.out.println("Mi-am bagat nasul");
				throw e.fillInStackTrace();
			}
		}
	}
	private static void method2() throws Throwable
	{
		Throwable objectException=new Throwable("Mesaj din adincuri");
		throw objectException;
	}
}