/* TestRelational.java
	Exemplu de testare operatori relationali
*/
public class TestRelational
{
	public static void main(String args[])
	{
		testPrimitive();
		testReference();
	}
	
	public static void testPrimitive()
	{
		int a=5;
		byte b=3;
		short c=5;
		System.out.println("Test realational operations for"+" primitive type");
		
		System.out.println(""+a+"="+b+" is "+(a==b));
		System.out.println(""+a+"!="+b+" is "+(a!=b));
		System.out.println(""+a+">"+b+" is "+(a>b));
		System.out.println(""+a+">="+b+" is "+(a>=b));
		System.out.println(""+a+"<"+b+" is "+(a<b));
		System.out.println(""+a+"<="+b+" is "+(a<=b));
		System.out.println(""+a+"="+c+" is "+(a==c));
		System.out.println(""+a+"!="+c+" is "+(a!=c));
		System.out.println(""+a+">"+c+" is "+(a>c));
		System.out.println(""+a+">="+c+" is "+(a>=c));
		System.out.println(""+a+"<"+c+" is "+(a<c));
		System.out.println(""+a+"<="+c+" is "+(a<=c));
	}
	public static void testReference()
	{
		Reference r1,r2,r3;
		r1=new Reference(1);
		r2=new Reference(1);
		r3=r1;
		System.out.println("Test realtional oprantions"+" for reference type");
		
		System.out.println(""+r1+"="+r2+" is "+(r1==r2));
		System.out.println(""+r1+"="+r2+" is "+r1.equals(r2));
		System.out.println(""+r1+"="+r3+" is "+(r1==r3));
		System.out.println(""+r1+"="+r3+" is "+r1.equals(r3));
	}
}

class Reference
{
	public int id;
	public Reference(int id)
	{
		this.id=id;
	}
	public boolean equals(Reference obj)
	{
		if(id==obj.id) return true;
		else return false;
	}
}