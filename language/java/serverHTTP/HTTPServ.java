/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Server HTTP.
	This file contains the implementation of server HTTP 1.0 class.
	
    Server HTTP is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Server HTTP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Server HTTP; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
import java.net.*;
import java.io.*;
import java.util.*;
import java.lang.*;
import java.nio.charset.Charset;
public class  HTTPServ extends Thread{
    protected BufferedReader insock;
    protected DataOutputStream outsock;
    protected FileInputStream fileread;
    protected File filereq;
    protected Socket sock;
    protected ServerSocket server;
    protected String command;
    protected String FileRequested;
    protected String GET=new String("GET");
    protected String PUT=new String("PUT");
    protected String home;
    protected Float mozilla;
    protected String header;
    protected FileWriter log;
    protected static Object SemLog=new Object();
    public HTTPServ(ServerSocket serv,String home,FileWriter wlog){ 
	server=serv;
	this.home=new String(home);
	log=wlog;
    };
    public void run(){
	while(true){
	try{
	    sock=server.accept();
	    insock=new BufferedReader(new InputStreamReader(sock.getInputStream()));
	    outsock=new DataOutputStream(sock.getOutputStream());
	}catch(IOException e){return;}
	while(true)
	{
	    try{
		String str1=new String(insock.readLine());
		if(str1.startsWith(GET)==true)
		    {
			command=str1;
			synchronized(SemLog){
			    InetAddress address=sock.getInetAddress();
				log.write(command+" from "+address.toString()+"\n");
				log.flush();
			};
		    }
		if(str1.startsWith("User-Agent: Mozilla/")==true)
			mozilla=new Float(str1.substring(20,23));
		if(str1.startsWith("Connection:")==true) break;
	    }
	    catch(Exception e){break;};
	}
	int pos=command.lastIndexOf(new String("HTTP/1."));
	if(pos==-1){
	    System.out.println("HTTP/1. not found");
	    try{
		sock.close();
	    }catch(Exception e1){};
	    return;
	}
	FileRequested=new String(home+command.substring(4,pos));
	try{
	    filereq=new File(FileRequested);
	    fileread=new FileInputStream(filereq);
	    byte[] filebyte=new byte[(int)filereq.length()];
	    fileread.read(filebyte);
	    fileread.close();
	    if(mozilla.floatValue()>=5.0)
		outsock.write(filebyte,0,(int)filereq.length());
	    else
		{
		    header=new String("HTTP/1.0 200 OK\n"+"Server: Gabriel Dimitriu\n"+"Content-length: "+filereq.length()+"\n\n");
		    outsock.writeBytes(header);
		    outsock.write(filebyte,0,(int)filereq.length());
		}
	    try{
		sock.close();
	    }catch(Exception e1){};
	}catch(Exception ef){
	    System.out.println(ef.getMessage());
	    try{
		header=new String("HTTP/1.0 404 Not Found\n\n");
		outsock.writeBytes(header);
		sock.close();
	    }catch(Exception e1){};
	};
	}
    }
}
