/*	TestFilterStreams.java
	Exemplu de utilizare a diferitelor clase derivate din FilterInputStream
*/
import java.io.*;
import java.util.*;

public class TestFilterStreams
{
	public static void main(String args[])
	{
		boolean exit=false;
		System.out.println("Let's play with different types of Filter streams");
		while(!exit)
		{
			System.out.println("\nWhat king of Filter streams");
			System.out.println("\t (1) OutFilterInputStreams");
			System.out.println("\t (2) DataStreams+BufferedStreams");
			System.out.println("\t (x) Exit");
			try
			{
				char readChar=(char)(System.in.read());
				int avlb=System.in.available();
				System.in.skip(avlb);
				if((readChar=='X')||(readChar=='x'))
				{
					exit=true;
					continue;
				}
				switch(readChar)
				{
					case '1': //hai sa ne jucam cu filtrarea
						//ne jucam cu clasa noastra derivata din FilterInputStream
						//filtreaza caracterele lasind doar cifrele neschimbate
						//celelalte le inlocuieste cu caracterul 'x'
						//observati conectarea cu un stream FileInputStream
						FigureFilterInputStream filter=new FigureFilterInputStream(new FileInputStream("test.txt"));
						int byteRead;
						while((byteRead=filter.readFigure())!=-1)
							System.out.print((char)byteRead);
						System.out.println();
						filter.close();
						break;
					case '2'://observati conectarea a trei stream-uri si folosirea unui nivel de buffer-are
						DataOutputStream out=new DataOutputStream(new BufferedOutputStream(new FileOutputStream("testDataStream.dat")));
						//scriem diferite tipuri de date in stream
						boolean booleanVar=true;
						System.out.println("Writes in file boolean:"+booleanVar);
						out.writeBoolean(booleanVar);
						byte byteVar=1;
						System.out.println("Writes in file byte:"+byteVar);
						out.writeByte(byteVar);
						short shortVar=2;
						System.out.println("Writes in file short:"+shortVar);
						out.writeShort(shortVar);
						int intVar=3;
						System.out.println("Writes in file int:"+intVar);
						out.writeInt(intVar);
						long longVar=4;
						System.out.println("Writes in file long:"+longVar);
						out.writeLong(longVar);
						float floatVar=4.35f;
						System.out.println("Writes in file float:"+floatVar);
						out.writeFloat(floatVar);
						double doubleVar=4E-1;
						System.out.println("Writes in file double:"+doubleVar);
						out.writeDouble(doubleVar);
						char charVar='x';
						System.out.println("Writes in file char:"+charVar);
						out.writeChar(charVar);
						String stringVar="This string is used"+" for test UTF format";
						System.out.println("Writes in file string:"+stringVar);
						out.writeUTF(stringVar);
						//le fortam sa mearga in fisier
						out.flush();
						//e corect nurmarul de bytes trimis ?
						System.out.println("The number of bytes written in stream is:"+"\n+1 (boolean)+1(bytes)+2(short)+4(int) +8(long)+4(float)+8(double)+\n"+"2(char)+"+stringVar.length()+"(Sting)+2="+out.size());
						out.close();
						//acum citim datele din fisier
						//ordinea citirii lor trebuie sa fie aceeasi cu ordinea scrierii lor
						//daca nu apare bulibaseala datelor
						System.out.println("\nNow let's read the file");
						DataInputStream in=new DataInputStream(new BufferedInputStream(new FileInputStream("testDataStream.dat")));
						System.out.println("Boolean="+in.readBoolean());
						System.out.println("Byte="+in.readByte());
						System.out.println("Short="+in.readShort());
						System.out.println("Int="+in.readInt());
						System.out.println("Long="+in.readLong());
						System.out.println("Float="+in.readFloat());
						System.out.println("Double="+in.readDouble());
						System.out.println("Char="+in.readChar());
						System.out.println("String="+in.readUTF());
						in.close();
				}//end switch
			}
			catch(IOException e)
			{
				System.err.println(e.getMessage());
			}
		}//end while
	}
}

class FigureFilterInputStream extends FilterInputStream
{
	public FigureFilterInputStream(InputStream in)
	{
		super(in);
	}
	//adauga o metoda care citeste un byte si il verifica daca este cifra
	int readFigure() throws IOException
	{
		int readByte=read();
		//anajuns la capatul tunelului...
		//si apare luminita -1
		if(readByte==-1) return readByte;
		//nu modific daca este sfirsit de linie
		if(readByte=='\r'||readByte=='\n') return readByte;
		//nici dac e cifra '1'=48
		if((readByte>=48)&&(readByte<58)) return readByte;
		//dar daca e altceva am un X in files
		else return 's';
	}
}