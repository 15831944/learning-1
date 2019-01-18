public class TestInterfaces
{
	public static void main(String args[])
	{
		SwimTeacher t=new SwimTeacher();
		Programmer p=new Programmer();
		whatHeRead(t);whatHeRead(p);
		whatHeWrite(t);whatHeWrite(p);
		whatHeThink(t);whatHeThink(p);
	}
	public static void whatHeRead(Reader r)
	{
		r.read();
	}
	public static void whatHeWrite(Writer r)
	{
		r.write();
	}
	public static void whatHeThink(Thinker r)
	{
		r.think();
	}
}
interface Reader
{
	public void read();
}
interface Writer
{
	public void write();
}
interface Professor extends Reader,Writer
{
	int MAX_MARK=10;
	int MIN_MARK=1;
	public void apreciate();
}
interface Diver
{
	int h=10;
	public void dive();
}
class Swimmer implements Diver
{
	static final int l=50;
	public void swim()
	{
		System.out.println("Swim "+l+"meters");
	}
	public void dive()
	{
		System.out.println("Dive from"+h+"meters");
	}
}
interface Thinker
{
	public void think();
}
class SwimTeacher extends Swimmer implements Professor,Thinker
{
	public void read()
	{
		System.out.println("Read Penthouse..");
	}
	public void write()
	{
		System.out.println("Write tatoos...");
	}
	public void apreciate()
	{
		System.out.println("You are stupid .. You get "+MIN_MARK);
	}
	public void think()
	{
		System.out.println("Hey Baby,... I can teach you swimming ..");
	}
}
class Programmer implements Reader,Writer,Thinker
{
	public void read()
	{
		System.out.println("Read Byte...");
	}
	public void write()
	{
		System.out.println("Write OOP...");
	}
	public void think()
	{
		System.out.println("Java is the best ...");
	}
}