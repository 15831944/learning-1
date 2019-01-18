import java.awt.Color;
import java.io.*;

public class TestDisplay
{
	public static void main(String args[])
	{
		//urmatorul cod il vom explica la momentul respectiv
		//scopul este de redirectionare a iesirii catre fisierul out.txt
		try
		{
			System.setOut(new PrintStream(new FileOutputStream("out.txt")));
		}
		catch(IOException e){}
		
		System.out.println("Lets take a look inside "+"classes and objects:");
		System.out.println("Declarare screen1 and screen2");
		Display screen1,screen2;//declaram doua obiecte de tip Display
		System.out.println("\nInstatiate screen1");
		screen1=new Display();//instantiere primul obiect
		System.out.println("\nInstatiate screen2");
		screen2=new Display();//instantiere al doilea obiect
		System.out.println("\nDeclare and instantiate screen3");
		Display screen3=new Display(1024,768,Color.blue,Color.green);
		screen1.info();	//apelam o serie de metode
		screen2.info("About screen2");
		screen3.info("About screen3");
	}
}

class Display
{
	int width=initWidth(800);//declaratii si initializari atribute
	int height=initHeight(600);
	boolean blackwhite=initBlackWhite(true);
	Color backgound;	//doar declaratii de atribute
	Color fontColor;
	
	public Display()//un constructor fara parametrii
	{
		System.out.println("Inside Empty constructor.");
	}
	public Display(int width,int height) //un overloading constructor
	{
		System.out.println("Inside width and height constructor.");
		this.width=width;		//acces atribut prin this
		this.height=height;
	}
	public Display(int width,int height,Color bg,Color fc)
	{
		this(width,height);	//apel alt constructor
		System.out.println("Inside width,height,backgound, and"+" fontColor cosntructor.");
		blackwhite=false;
		backgound=bg;
		fontColor=fc;
	}
	private int initWidth(int width)//metode de test etape de initializare
	{
		System.out.println("Call initWidth.");
		System.out.print("\tField \"width\"="+this.width+".");
		System.out.println("Set width at "+width);
		return width;
	}
	private int initHeight(int height)
	{
		System.out.println("Call initHeight.");
		System.out.print("\tField \"height\"="+this.height+". ");
		System.out.println("Set height at "+height);
		return height;
	}
	private boolean initBlackWhite(boolean bw)
	{
		System.out.println("Call initBlackWhite.");
		System.out.println("\tFields \"blackwhite\"="+blackwhite+",\"backgound\"="+backgound+",\"fontColor\"="+fontColor+". ");
		System.out.println("\t Set blackwhite="+bw+",backgound="+(backgound=Color.black)+",fontColor="+(fontColor=Color.white));
		return bw;
	}
	public void info(String message) //metode redefinite
	{
		System.out.println("\n"+message);
		System.out.println("\twidth="+width+",height="+height+"blackwhite="+blackwhite+"\n\t backgound="+backgound+"\n\t fontColor="+fontColor);
	}
	public void info()
	{
		info("Inof about display.");
	}
}