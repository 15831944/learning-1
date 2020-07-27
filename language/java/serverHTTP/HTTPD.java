/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Server HTTP.
	This file contains the implementation of main class.
	
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
public class HTTPD{
    protected static String home=new String("public_html");
    protected static int maxThread=10;
    public static void main(String[] args)
	throws MalformedURLException, IOException {
	File logFile=new File("httpd.log");
	FileWriter log=new FileWriter(logFile);
	ServerSocket serversock=new ServerSocket(80);
	serversock.setReuseAddress(true);
	for(int i=0;i<maxThread;i++)
	    {
	    HTTPServ server=new HTTPServ(serversock,home,log);
	    server.start();
	    }
    }
}
