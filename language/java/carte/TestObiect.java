public class TestObiect
{
	public static void main(String args[])
	{
		Persoana p1=new Persoana("Corcode1",15);
		Persoana p2=new Persoana("Corcode1",15);
		Persoana p3=new Persoana("xyz",15);
		Persoana p4=null;
		try //ce-i cu try-catch o sa vedem putin mai incolo
		{
			p4=(Persoana)(p1.clone());
		}
		catch(Exception e){}
		System.out.println("p1="+p1);
		System.out.println("p2="+p2);
		System.out.println("p3="+p3);
		System.out.println("p4="+p4);
		
		System.out.println("p1==p2:"+(p1==p2));
		System.out.println("p1.equals(p2):"+p1.equals(p2));
		System.out.println("p1.equals(p3):"+p1.equals(p3));
		System.out.println("p1.equals(p4):"+p1.equals(p4));
	}
}
//pentru a putea fi cloanata o clasa trebuie sa implementeza Cloneable si sa supreascrie metoda clone
class Persoana implements Cloneable
{
	public String name;
	public int age;
	public Persoana(String name,int age)
	{
		this.name=name;
		this.age=age;
	}
	public String toString()//folsoita pentru a spune ce afisam laprintarea obiectului
	{
		return "Name="+name+"; age="+age;
	}
	public boolean equals(Object obj)
	{
		if(!(obj instanceof Persoana)) return false;	//nu-i nici macar Persoana
		Persoana pers=(Persoana)obj;	//fac un downcasting
		if(!name.equals(pers.name)) return false;	//au nume diferit
		if(age!=pers.age) return false;	//alta virsta
		return true;		//sunt identice
	}
	public Object clone() throws CloneNotSupportedException
	{
		return super.clone();	//folosesc metoda clone din clasa Object
	}
}