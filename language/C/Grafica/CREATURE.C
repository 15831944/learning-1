#include<conio.h>
#include<dos.h>
#include<graphics.h>
int x,y,dx,dy,Q,tasta;
void deseneaza(int x1,int y1,int flag)
{
/*
circle(x,y,10);
line(x,y-10,x,y-13);
line(x-2,y-9,x-5,y-13);
line(x+2,y-9,x+5,y-13);
circle(x-3,y-4,2);
circle(x+3,y-4,2);
line(x,y,x,y+3);
line(x-2,y+6,x-2,y+9); //colti
line(x+2,y+6,x+2,y+9); //colti
line(x-2,y+6,x+2,y+6);
line(x-2,y+6,x-3,y+5);
line(x+2,y+6,x+3,y+5);
*/
line(x,y+10,x,y+50);
line(x-20,y+25,x+20,y+25);
line(x-20,y+25,x-30,y+5);
//line(x+20,y+25,x+25,y+5);
line(x,y+50,x-10,y+80);
line(x,y+50,x+10,y+80);
line(x+10,y+80,x+15,y+80);
line(x-10,y+80,x-15,y+80);
if(flag==1)
setcolor(BLACK);
else setcolor(WHITE);
line(x+20,y+25,x1,y1);
if(flag==1)
setcolor(BLACK);
else setcolor(RED);
circle(x1,y1,10);
circle(x1-3,y1-4,2);
circle(x1+3,y1-4,2);
line(x1,y1-10,x1,y1-13);
line(x1-2,y1-9,x1-5,y1-13);
line(x1+2,y1-9,x1+5,y1-13);
line(x1,y1,x1,y1+3);
line(x1-2,y1+6,x1+2,y1+6);
line(x1-2,y1+6,x1-3,y1+5);
line(x1+2,y1+6,x1+3,y1+5);
line(x1-2,y1+6,x1-2,y1+9); //colti
line(x1+2,y1+6,x1+2,y1+9); //colti
setcolor(WHITE);
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