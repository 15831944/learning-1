#include<conio.h>
#include<dos.h>
#include<graphics.h>
int x,y,dx,dy,Q,tasta;
int puncte[10];
void deseneaza(int x1,int y1,int flag)
{
int i;
	puncte[0]=x-20;
	puncte[1]=y+25;
	puncte[2]=x+20;
	puncte[3]=y+25;
	puncte[4]=x+20;
	puncte[5]=y+40;
	puncte[6]=x;
	puncte[7]=y+70;
	puncte[8]=x-20;
	puncte[9]=y+40;
	if(flag==1)
	{
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		fillellipse(x1,y1,10,10);
		fillellipse(x1+11,y1,2,4);
		fillellipse(x1-11,y1,2,4);
		fillpoly(5,puncte);
		fillellipse(x,y+40,8,15);
		bar(x-2,y+10,x+2,y+25);
		bar(x-2,y+55,x+2,y+75);
		for(i=0;i<4;i++)
		{
			line(x-i,y+50,x-10-i,y+80);
			line(x+i,y+50,x+10+i,y+80);
		}
		bar(x-20,y+24,x+20,y+26);
		setfillstyle(SOLID_FILL,BLACK);
		fillellipse(x1-3,y1-4,2,2); //eyes
		fillellipse(x1+3,y1-3,2,2); //eyes
		line(x+10,y+80,x+15,y+80);
		line(x-10,y+80,x-15,y+80);
		for(i=0;i<3;i++)
		{
			line(x-20-i,y+25,x-30-i,y+50);
			line(x+20+i,y+25,x1+i,y1);
		}
		bar(x-30,y,x-28,y+50);
		for(i=0;i<6;i=i+2)
		{
			line(x-28-i,y+50,x-20-i,y+70);
			line(x-28-i,y+50,x-28-i,y+70);
			line(x-28-i,y+50,x-36-i,y+70);
		}
	}
	else
	{
		setcolor(BROWN);
		for(i=0;i<3;i++)
		{
			line(x-20-i,y+25,x-30-i,y+50);
			line(x+20+i,y+25,x1+i,y1);
		}
		setcolor(LIGHTRED);
		setfillstyle(SOLID_FILL,LIGHTRED);
		fillellipse(x1,y1,10,10);
		fillellipse(x1+11,y1,2,4);
		fillellipse(x1-11,y1,2,4);
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		fillpoly(5,puncte);
		setcolor(GREEN);
		setfillstyle(SOLID_FILL,GREEN);
		fillellipse(x,y+40,8,15); //body
		bar(x-2,y+55,x+2,y+75);
		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL,MAGENTA);
		bar(x-2,y+10,x+2,y+25);   //neck
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		fillellipse(x1-3,y1-4,2,2); //eyes
		fillellipse(x1+3,y1-3,2,2); //eyes
		setcolor(BROWN);
		setfillstyle(SOLID_FILL,BROWN);
		line(x+10,y+80,x+15,y+80); //foot
		line(x-10,y+80,x-15,y+80); //foot
		bar(x-20,y+24,x+20,y+26);
		for(i=0;i<4;i++)
		{
			line(x-i,y+50,x-10-i,y+80);
			line(x+i,y+50,x+10+i,y+80);
		}
		bar(x-30,y,x-28,y+50);
		setcolor(DARKGRAY);
		for(i=0;i<6;i=i+2)
		{
			line(x-28-i,y+50,x-20-i,y+70);
			line(x-28-i,y+50,x-28-i,y+70);
			line(x-28-i,y+50,x-36-i,y+70);
		}
	}
	if(flag==1) setcolor(BLACK);
	else setcolor(RED);
	line(x1,y1-10,x1,y1-13);
	line(x1-2,y1-9,x1-5,y1-13);
	line(x1+2,y1-9,x1+5,y1-13);
	line(x1,y1,x1,y1+3);
	line(x1-2,y1+6,x1+2,y1+6);
	line(x1-2,y1+6,x1-3,y1+5);
	line(x1+2,y1+6,x1+3,y1+5);
	if(flag==1) setcolor(BLACK);
	else setcolor(WHITE);
	line(x1-2,y1+6,x1-2,y1+9); //colti
	line(x1+2,y1+6,x1+2,y1+9); //colti
}
void sterge(int x1,int y1)
{
	setcolor(BLACK);
	deseneaza(x1,y1,1);
	setcolor(WHITE);
}
void main()
{
int gm,gd=DETECT;
int xa,ya,i,z;
x=300;
y=300;
Q=0;
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	deseneaza(x,y,2);
	xa=x;ya=y;
	do
	{
	 dx=0;dy=0;
	 if(kbhit())
	 {
		 tasta=getch();
		 if(tasta==0) tasta=getch();
		 switch(tasta)
		 {
			case 72: dy=-1;break;
			case 80: dy=1;break;
			case 75: dx=-1;break;
			case 77: dx=1;break;
			case 27: Q=1; break;
		 }
		 sterge(xa,ya);
		 x+=10*dx;
		 y+=10*dy;
		 xa=x+27;
		 z=ya=y-5;
		 for(i=0;i<10;i++)
		 {
			 deseneaza(xa,ya,1);
			 ya=z+i*10;
			 deseneaza(xa,ya,2);
			 delay(10);
		 }
		 z=ya;
		 for(i=0;i<10;i++)
		 {
			 deseneaza(xa,ya,1);
			 ya=z-i*10;
			 deseneaza(xa,ya,2);
			 delay(10);
		 }
		 deseneaza(xa,ya,1);
		 xa=x;
		 ya=y;
		 deseneaza(xa,ya,2);
	}
 }
 while(Q!=1);
}