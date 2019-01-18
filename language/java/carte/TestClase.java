import java.io.*;
import java.util.*;

class MulXY1                                          
{
   public double x,y;
   public void MulXY1()
   {
   }
	public void execute1()
   {
   	System.out.println("X="+x+"  Y="+y);
   	System.out.println("X*Y="+x*y);
   }
}

class MulXY2 extends MulXY1
{
	public void execute2()
	{
		System.out.println("X="+x+" Y="+y);
		System.out.println("X*Y="+x*y/10);
	}
	public void execute1()
	{
		super.execute1();
	}
}
                              
public class TestClase
{
	public static void main(String args[])
	{
		MulXY1 clasa1;
		clasa1=new MulXY1();
		MulXY2 clasa2;
		clasa2=new MulXY2();
		clasa1.x=clasa2.x=1.0;
		clasa1.y=clasa2.y=3.0;
		clasa1.execute1();
		clasa2.execute2();
	}
}
		