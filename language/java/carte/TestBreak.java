/* TestBreak.java
	Exemplu pentru instructiunea break.
*/
public class TestBreak
{
	public static void main(String args[])
	{
		testBreak();
	}
	static void testBreak()
	{
		high_level:
		{
			System.out.println("/nEnter in High level");
			middle_level:for(int i=0;i<4;i++)
			{
				System.out.println("Enter in Middle level cicle");
				int j=0;
				low_level:while(j++<2)
				{
					System.out.println("Enter in Low level cicle");
					System.out.println("i="+i+";j="+j);
					switch(i)
					{
						case 0: break;
						case 1: break low_level;
						case 2: break middle_level;
						case 3: break high_level;
					}
					System.out.println("Exit from Low level cicle");
				}
				System.out.println("Exit from Middle level cicle");
			}
			System.out.println("Exit from High level");
		}
	}
}