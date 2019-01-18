/* HelloUsers.java
	Preia parametrii din linia de comanda. Utilizatorl poate da mai multe nume si programul saluta pe tota lumea.
*/

	class HelloUsers
	{
		public static void main(String args[])
		{
			if(args.length==0)//daca nu sunt argumente
			{
				System.out.println("Why are you so shy? Give me yourname!");
				return;
			}
			for(int i=0;i<args.length;i++)
				System.out.println("Hi "+args[i]+"!");
			System.out.println("Au fost " +args.length+ " argumente");
		}
	}