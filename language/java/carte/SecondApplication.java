/*	SecondApplication.java
	Aplicatie de la pagina 58
*/
class Point
{
	/* declaratie clasa Point,
		are doua atribute public x si y reprezentind coordonatele punctului
		public arata ca atributul poate fi accesat din alata clasa
		atributele sunt initializate la valoarea 0
	*/
	public int x=0;
	public int y=0;
	public Point(){} //constructor faca nici un parametru
	public Point(int varx,int vary) //constructor cu doi parametrii
	{
		x=varx;
		y=vary;
	}
}

class Rectangle
{
	Point origin=new Point(0,0); //atribut de tip Point urmat de expresia de initializare
	int width=0,height=0;	//atribute de tip int initializate la val 0
	public Rectangle(){}	//constructor fara parametrii
	public Rectangle(int w,int h) //constructor cu doi parametrii
	{
		width=w;height=h;
	}
	public Rectangle(Point o,int w,int h)//constructor cu trei parametrii
	{
		origin=o;	//atribuire de obiect Point
		width=w;height=h;
	}
	//urmeaza metodele de exploatare a clasei
	public int getArea()	//calculeaza si returneaza suprafata dreptunghiului
	{
		return width*height;
	}
	public Point getCenter()//determina si returneaza centrul dreptunghiului
	{
		int x=(origin.x+width)/2;
		int y=(origin.y+height)/2;
		Point center=new Point(x,y);
		return center;
	}
}

class SecondApplication
{
	public static void main(String s[])
	{
		Rectangle rect=new Rectangle(new Point(5,5),100,50);
		Point center=rect.getCenter();
		System.out.println("Centrul este la " +center.x +center.y);
		System.out.println("Aria este " +rect.getArea());
	}
}