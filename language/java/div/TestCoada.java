/* teste pour queue */
import java.io.*;

class Queue
{
	private char string;
	public Queue apres;
	public Queue(char str)
	{
		string=str;
		apres=(Queue)null;
	}
	public Queue()
	{
		System.out.println("Erreur de initialization");
	}
	public Queue efacher()
	{
		return apres;
	} 
	public void printe()
	{
		System.out.println("La value est "+string);
	}
}

public class TestCoada
{
	public static void main(String args[])
	{
	int read=1;
	String temp;
	Queue start=null;
	Queue temporar=null;
	Queue fin=null;
		System.out.println("Introduise le numero moins 10");
		try
		{
			read=(int)(System.in.read())-48;
			int avail=System.in.available();
			System.in.skip(avail);
		}
		catch(IOException e)
		{
			System.err.println(e.getMessage());
		}
		System.out.println("Introduise les characters");
		start=fin=(Queue)null;
		for(int i=0;i<read;i++)
		{
			try
 			{
				temp=(char)System.in.read();
				int avlb=System.in.available();
				System.out.println(avlb);
				System.in.skip(avlb);
			}
			catch(IOException e)
			{
				System.err.println(e.getMessage());
			}
			temporar=new Queue(temp);

			if(i==0)
			{
				start=fin=temporar;
			}
			else
			{
				fin.apres=temporar;
				fin=temporar;
			}
		}
		temporar=start;
		for(int i=0;i<read;i++)
		{
			temporar.printe();
			temporar=temporar.apres;
		}
		System.out.println("Efacher un component");
		start=start.efacher();
		temporar=start;
		while(temporar!=(Queue)null)
		{
			temporar.printe();
			temporar=temporar.apres;
		}
	}
}