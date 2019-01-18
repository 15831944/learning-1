/*	ApplicApplet.java
	Cadrul unui program Java care poate lucra si ca applet si ca aplicatie. Este un program care afiseaza n sir ce aluneca de la dreapta la stinga.
*/

	import java.applet.*;
	import java.awt.*;
	import java.awt.event.*;
	
	public class ApplicApplet extends Applet implements Runnable
	{
		private Thread ourThread=null;	//firul de executie
		private boolean applic=false;		//flag pentru semnalizare aplicatie sau applet
		private static int dimX=300,dimY=200;	//dimensiune applet
		//variabile specifice programului
		private int posx,posy;	//pozitiile de afisare sir
		
		//metoda main este apelata doar in cazul aplicatiei
		public static void main(String args[])
		{
			//creaza o fereastra
			Frame frame=new Frame("Application or Applet");
			//clasa necesara inchiderii ferestrei aplicatie
			//este o clasa interioara
			class FrameClose extends WindowAdapter
			{
				public void windowClosing(WindowEvent e)
				{
					System.exit(0);
				}
			}
			
			frame.addWindowListener(new FrameClose());
			ApplicApplet applet=new ApplicApplet();
			applet.applic=true;	//semnalizez aplicatie
			
			frame.add(applet,BorderLayout.CENTER);
			frame.setSize(dimX,dimY);
			applet.init();
			applet.start();
			frame.setVisible(true);
		}
		
		public ApplicApplet(){} //constuctor
		
		public String getAppletInfo()//apelata de browser la cererea utilizatorului
		{
			return "Name: Application or Applet\r\n"+ "Author: Gabriel Dimitriu\r\n";
		}
		
		//metode mostenite de la clasa Applet
		public void init()//metoda apelata de browser la prima lansare in executie a appletului
		{
			setSize(dimX,dimY);
			posx=20;
			posy=200;
		}
		
		public void start() //metoda apelata de browser cind se intra in pagina html a applet-ului
		{
			if(ourThread==null)
			{
				ourThread=new Thread(this);		//cream thread
				ourThread.start();					//pornim thread-ul
			}
		}
		
		public void stop()//metoda apelata de browser cind se iese din pagina html a applet-ului
		{
			if(ourThread!=null)
			{
				ourThread.stop();	//oprim firul de executie
				ourThread=null;	//stergem orice urma a lui
			}
		}
		public void destroy(){}//metoda utilizata pentru a face curatenie
		
		//metoda de desenare
		public void paint(Graphics g)
		{
			g.drawString("This can run as an application or as an applet",posx,posy);
		}
		
		//metoda run utilizata pentru a implemanta interfata Runnable
		//este specifica lucrului multithreading
		public void run()
		{
			while(true)
			{
				try
				{
					posx+=5;	//deplasez sirul
					if(posx>dimX) posx=0;
					repaint(); //cer redesenare
					Thread.sleep(100);	//adorm thread-ul pentru a ceda rindul altora
				}
				catch(InterruptedException e){stop();}
			}
		}
	}