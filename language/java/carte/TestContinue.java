/* TestContinue.java
	Exemplu pentur instructiunea continue.
*/
class TestContinue
{
	public static void main(String args[])
	{
		testContinue();
	}
	static void testContinue()
	{
		high_level:
		{
			System.out.println("\n Enter in High level");
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
						case 0: continue;
						case 1: continue low_level;
						case 2: continue middle_level;
						case 3: break high_level;
						//continue nu poate fi utilizat decit in interiorul unei intructiuni de ciclare
					}
					System.out.println("Exit from Low level cicle");
				}
				System.out.println("Exit from Middle level cicle");
			}
			System.out.println("Exit from High level");
		}
	}
}