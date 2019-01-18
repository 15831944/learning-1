/*	FirstApplet.java
	Primul nostru applet java. Programul va afisa textul "This is your first Java applet
	in zona alocata applet-ului de catre browser.
*/
	import java.applet.Applet;
	import java.awt.Graphics;
	
	public class FirstApplet extends Applet
	{
		public void paint(Graphics g)
		{
			g.drawString("This is our first Java applet",30,30);
		}
	}
//----------------------------