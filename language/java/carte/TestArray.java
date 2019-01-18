/* TestArray.java
	Exemplu de taboru unidimensional.
*/
class TestArray
{
	public static void main(String args[])
	{
		TestArray test=new TestArray();
		int a[]=test.createArray(6);
		test.printArray("a=",a);
		
		int[] alias=a;	//se creaza alias-ul tabloului
		//se cloneaza tabloul. Metoda clone a clasei Obiect returneaza un Obiect asa ca 
		//trebuie facut un cast la tipul tablou de int, cast care se face prin (int[])
		int[] clone=(int[])a.clone();
		
		test.reverseArray(a);	//inversam elementele tabloului
		//si tiparim cele trei tablouri
		test.printArray("a=",a);
		test.printArray("alias=",alias);
		test.printArray("clone=",clone);
	}
	
	public int[] createArray(int l)
	{
		int[] tab=new int[l];
		for(int i=0;i<l;i++) tab[i]=i;
		return tab;
	}
	
	public void reverseArray(int[] tab)
	{
		for(int i=0;i<tab.length/2;i++)
		{
			int temp=tab[i];
			tab[i]=tab[tab.length-1-i];
			tab[tab.length-1-i]=temp;
		}
	}
	
	public void printArray(String m,int[] tab)
	{
		System.out.println("\r\n"+m);
		for(int i=0;i<tab.length;i++)
			System.out.print("     "+tab[i]);
		}
	}