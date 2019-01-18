/* TestException.java */
public class TestException
{
	public static void main(String args[])
	{
		System.out.println("Hai sa dam notele");
		for(int i=10;i>=1;i--)
		{
			try
			{
				System.out.println("\n Proful: Dau un:"+i);
				method1(i);
				System.out.println("Vad ca e bine");
			}
			catch( Exception e)
			{
				System.out.println("Pila a zis:"+e.getMessage());
				System.out.println("Proful:Exceptia confirma regula");
			}
		}
	}
	//urmeaza o ierarhie de metode statice care se apelaza una pe alta
	private static void method1(int nota) throws Exception
	{
		//Secretara hai sa la afisam
		System.out.println("Secretara: Afisez "+nota);
		method2(nota);
	}
	private static void method2(int nota) throws Exception
	{
		if(nota<5)
		{
			System.out.println("Sudentul: Hai sa sar la cap..");
			Exception pila=new Exception("Treceti-l va rog");
			throw pila;
		}
		else System.out.println("Studentul: Am scapat...");
	}
}