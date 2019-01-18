/* FirstIO1.java
	Exemplu de introducere a primelor notiuni de lucru cu System.in sis System.out
*/

import java.io.*; //pt a lucra cu stream-uri trebuie sa importam acest package
import java.util.*;

class FirstIO1
{
	public static void main(String args[])
	{
		boolean exit=false;	//flag de iesire
		System.out.println("Let's play with IO and see some \n"+
		"information about our system");
		while(!exit) //pana nu am setat flag-ul de iesire
		{
			//afisam optiunile
			System.out.println("See what ?....(Options):");
			System.out.println("\t (D) Date");
			System.out.println("\t (P) Propreties");
			System.out.println("\t (X) Exit");
			try
			{
			//	System.setOut(new PrintStream(new FileOutputStream("out.txt"))); //deprecated
				char readChar=(char)(System.in.read());
				int avlb=System.in.available();
				System.in.skip(avlb);
				switch(readChar)
				{
					case 'D': case 'd': //afisam date
						System.out.println("Date:"+new Date().toString());
						break;
					case 'P': case 'p': //afisam proprietatile sistemului
						Properties prop=System.getProperties();
						prop.list(System.out);
						break;
					case 'X': case 'x': //iesim afara
						System.out.println("See you soon my friend!");
						exit=true;
						break;
				}
			}
			catch(IOException e)
			{
				System.err.println(e.getMessage());
			}
		} //end while
	}
}