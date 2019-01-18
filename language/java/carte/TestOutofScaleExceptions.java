/*
	Exemplu de creare a unei ierarhii de clase detip exceptie
*/
public class TestOutofScaleExceptions
{
	public static void main(String args[])
	{
		BarDisplay barDisplay=new BarDisplay(5,15);
		int testVal[]={7,14,3,19};
		for(int i=0;i<testVal.length;i++)
		{
			try
			{
				System.out.println();
				barDisplay.setValue(testVal[i]);
				System.out.println("It seems OK");
				barDisplay.show();
			}
			catch(OutOfScaleException e)
			{
				e.printStackTrace();
			}
		}
	}
}
abstract class Display
{
	int min,max;
	int pos;
	public Display(int min,int max)
	{
		this.min=min;
		this.max=max;
		pos=min;
	}
	public void setValue(int pos) throws OutOfScaleException
	{
		if(pos<min) throw new TooLittleException(min,max,pos);
		if(pos>max) throw new TooBigException(min,max,pos,"I am full");
		this.pos=pos;
	}
	public abstract void show();
}
class BarDisplay extends Display
{
	public BarDisplay(int min,int max)
	{
		super(min,max);
	}
	public void show()
	{
		System.out.println();
		for(int i=0;i<pos;i++) System.out.print("*");
		System.out.println();
	}
}
class OutOfScaleException extends Exception
{
	int max,min,pos;
	public OutOfScaleException(int min,int max,int pos, String message)
	{
		super(message);
		this.pos=pos;
		this.pos=pos;
		this.min=min;
		this.max=max;
	}
	public OutOfScaleException(int min,int max,int pos)
	{
		this(min,max,pos,"OutOfScale");
	}
	public String getMessage()
	{
		return super.getMessage()+":"+pos+" should be inside ["+min+","+max+"]";
	}
}
class TooBigException extends OutOfScaleException
{
	public TooBigException(int min,int max,int pos,String message)
	{
		super(min,max,pos,message);
	}
	public TooBigException(int min,int max,int pos)
	{
		super(min,max,pos,"Too Big");
	}
}
class TooLittleException extends OutOfScaleException
{
	public TooLittleException(int min,int max,int pos,String message)
	{
		super(min,max,pos,message);
	}
	public TooLittleException(int min,int max,int pos)
	{
		super(min,max,pos,"Too Little");
	}
}