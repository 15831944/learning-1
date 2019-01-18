import java.awt.Color;
//clasa Filozof implementeaza comportamentul unui concurent
class Filozof extends Thread
{
	//parerea concurentul despre culoarea palariei sale. Null daca inca nu si-a format o parere
	Color parere=null;
	Filozof(String nume)
	{
		super(nume);
	}
	public void run()
	{
		//concurentii firului curent
		Filozof concurenti[]=new Filozof[2];
		//temporar
		Thread fire[]=new Thread[10];
		int numarFire=enumerate(fire);
		for(int i=0,j=0;i<numarFire&&j<2;i++)
		{
			if(fire[i] instanceof Filozof&&fire[i]!=this)
			{
				concurenti[j++]=(Filozof)fire[i];
			}
		}
		while(true)
		{
			Color primaCuloare=Concurs.culoare(this,concurenti[0]);
			Color adouaCuloare=Concurs.culoare(this,concurenti[1]);
			if(primaCuloare==Color.white && adouaCuloare==Color.white)
			{
				synchronized(this){ 
					parere=Color.black; 
				};
			}
			else if(primaCuloare==Color.white)
			{
				try
				{
					sleep(50);
				}catch(InterruptedException e)
				{};
				if(Concurs.culoare(this,concurenti[1])!=concurenti[1].aGhicit())
				{
					synchronized(this){
						parere=Color.black;
					};
				}
			}
			else if(adouaCuloare==Color.white)
			{
				try
				{
					sleep((int)(Math.random()*5));
				}catch(InterruptedException e){};
				if(Concurs.culoare(this,concurenti[0])!=concurenti[0].aGhicit())
				{
					synchronized(this){
						parere=Color.black;
					};
				}
			}
			else
			{
				try
				{
					sleep((int)(Math.random()*5)+5);
				}catch(InterruptedException e){};
				if(Concurs.culoare(this,concurenti[0])!=concurenti[0].aGhicit()&&Concurs.culoare(this,concurenti[1])!=concurenti[1].aGhicit())
				{
					synchronized(this){
						parere=Color.black;
					};
				}
			}
		}
	}
	public synchronized Color aGhicit()
	{
		return parere;
	}
}

public class Concurs
{
	private static Color palarii[]={ Color.black,Color.black,Color.black};
	private static Filozof filozofi[]=new Filozof[3];
	private static int j;
	public static void main(String args[])
	{
		for(int i=0;i<args.length&&i<3;i++)
		{
			if(args[i].equalsIgnoreCase("alb"))
			{
				palarii[i]=Color.white;
			}
			else if(args[i].equalsIgnoreCase("negru"))
			{
				palarii[i]=Color.black;
			}
		}
		for(int i=0;i<3;i++)
		{
			filozofi[i]=new Filozof("Filozoful "+(i+1));
		}
		for(int i=0;i<3;i++)
		{
			filozofi[i].start();
		}
		System.out.println("Concurenti:");
		for(int i=0;i<3;i++)
		{
			System.out.println("\t"+filozofi[i].getName() + " "+((palarii[i]==Color.white)?"alb":"negru"));
		}
		j=0;
		gata:
		while(j!=4)
		{
			for(int i=0;i<3;i++)
			{
				if(filozofi[i].aGhicit()==palarii[i])
				{
					System.out.println(filozofi[i].getName()+"a ghicit.");
					j=j+1;
					break gata;
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			filozofi[i].stop();
			try
			{
				filozofi[i].join();
			}catch(InterruptedException e){};
		}
	}
	public static Color culoare(Filozof filozof,Filozof concurent)
	{
		if(filozof!=concurent)
		{
			for(int i=0;i<3;i++)
			{
				if(filozofi[i]==concurent)
				{
					return palarii[i];
				}
			}
		}
		return null;
	}
}