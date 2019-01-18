/* TestInputStream.java
	Exemplu de testare clase de tip
*/
import java.io.*;
import java.util.*;

public class TestInputStream
{
	public static void main(String args[])
	{
		boolean exit=false;
		System.out.println("Let's play with different types of streams");
		//se repeta pina cind se face exit=true
		while(!exit)
		{
			//se scriu optiunile
			System.out.println();
			System.out.println("What kind of stream");
			System.out.println("\t (1) ByteArrayInputStream");
			System.out.println("\t (2) StringBufferInputStream -deprecated");
			System.out.println("\t (3) FileInputStream");
			System.out.println("\t (4) SequenceInputStream");
			System.out.println("\t (x) Exit");
			//este nevoie de un bloc try-catch deoarece fuctiile read includ in
			//definitia lor throws IOException
			try
			{
				//se citeste primul caracter tastat
				char readChar=(char)(System.in.read());
				//restul caracterelor se englijeaza
				int avlb=System.in.available();
				System.in.skip(avlb);
				InputStream bufferStream;
				//daca se doreste iesirea se seteaza flagul de iesire exit
				//si se sare la verificarea conditiei while
				if((readChar=='X')||(readChar=='x'))
				{
					exit=true;
					continue;
				}
				//nu vrem exit
				switch(readChar)
				{
					case '1': //vrem un ByteArrayInputStream
						bufferStream=getByteArrayInputStream();
						break;
					case '2': //ba nu.Un StringBufferInputStream desi e deprecated
						bufferStream=getStringBufferInputStream();
						break;
					case '3': //nuuuu. vream FileInputStream
						bufferStream=getFileInputStream();
						break;
					case '4': //???? baaa... vream SequenceInputStream
						bufferStream=getSequenceInputStream();
						break;
					default: //..nici citeva litere nu le poate tipari corect ?
						bufferStream=getStringBufferInputStream("No valid selection");
				}
				
				//afisam ce citim din stram byte cu cyte...
				int byteRead;
				while((byteRead=bufferStream.read())!=-1)
					System.out.print((char)byteRead);
				System.out.println();
				//Ai terminat !!! ... Fa curat
				bufferStream.close();
			}
			catch(IOException e)//exceptie printez la user
			{
				System.err.println(e.getMessage());
			}
		}
	}
	
	//cream metode statice care pot fi apelate din main fara a crea un obiect
	
	private static InputStream getByteArrayInputStream()
	{
		//construim un tablou de 10 bytes continind codurile ASCII ale
		//primelor 10 cifre 1=0x30,2-0x30+1 ...etc
		byte buffer[]=new byte[10];
		for(byte i=0;i<buffer.length;buffer[i]=(byte)(0x30+i++));
		//cream si stream-ul
		ByteArrayInputStream bufferStream=new ByteArrayInputStream(buffer);
		return bufferStream;
	}
	
	private static InputStream getStringBufferInputStream(String buffer)
	{
		StringBufferInputStream bufferStream=new StringBufferInputStream(buffer);
		//se recomanda utilizarea clasei StringReader
		return bufferStream;
	}
	
	private static InputStream getStringBufferInputStream()
	{
		return getStringBufferInputStream("Test StringBufferInputStream");
	}
	
	private static InputStream getSequenceInputStream()
	{
		//ne jucam cu cubuletile... Doar ca de data asta cubuletele sunt strem-uri de tip Sting
		InputStream bufferStream, grup1;
		grup1=new SequenceInputStream(new StringBufferInputStream("Stream1 ..."),
												new StringBufferInputStream("Stream2 ..."));
		Vector grup2=new Vector(3);
		grup2.addElement(grup1);
		grup2.addElement(new StringBufferInputStream("Stream3 ..."));
		grup2.addElement(new StringBufferInputStream("Stream4 ..."));
		bufferStream=new SequenceInputStream(grup2.elements());
		return bufferStream;
	}
	
	private static InputStream getFileInputStream()
	{
		InputStream bufferStream;
		//trebuie try-catch,.. Daca nu gasim fisierul
		try
		{
			//Ia sa punem conducta la fisier
			bufferStream=new FileInputStream("test.txt");
		}
		catch(FileNotFoundException e)
		{
			bufferStream=new StringBufferInputStream("File "+e.getMessage()+" Not found!");
		}
		return bufferStream;
	}
}