/* TestMultiArray.java
	Exemplu pentru tablouri multidimensionale.
*/
class TestMultiArray
{
	public static void main(String args[])
	{
		testMultiArray();
	}
	public static void testMultiArray()
	{
		int[][] tab;
		System.out.println("Create a rectangular bidimensional array tab=");
		tab=new int[10][10];
		for(int i=0;i<tab.length;i++)
		{
			System.out.println();
			for(int j=0;j<tab[i].length;j++)
			{
				tab[i][j]=10*i+j;
				System.out.print(" "+tab[i][j]);
			}
		}
		System.out.println("\n\n Create a non rectangular bidimensional"+
		"array tab=");
		tab=new int[10][];
		for(int i=0;i<tab.length;i++)
		{
			System.out.println();
			tab[i]=new int[i+1];
			for(int j=0;j<tab[i].length;j++)
			{
				tab[i][j]=10*i+j;
				System.out.print(" "+tab[i][j]);
			}
		}
		
		System.out.println("\n\n Let's Take some elements from tab");
		int l=5;
		int[] tab1=tab[l];
		System.out.print("\n Linia "+l+":");
		for(int i=0;i<tab1.length;i++)
			System.out.print(" "+tab1[i]);
		int k=3;
		int elem=tab[l][k];
		System.out.println("\n Element tab["+l+","+k+"]="+elem);
	}
}
			