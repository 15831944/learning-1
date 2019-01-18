import java.io.*;
import java.util.*;
public class TestRead
{	
	public static void main(String args[])
	{
		int test=0,nr=0;
		try
		{
			DataInputStream in=new DataInputStream(new BufferedInputStream(new FileInputStream("test.dat")));
			nr=in.readInt();
			for(int i=0;i<nr;i++)
			{
				System.out.println("val="+in.readInt());
			}
			in.close();
		}
		catch(IOException e)
		{
			System.err.println(e.getMessage());
		}
	}
}