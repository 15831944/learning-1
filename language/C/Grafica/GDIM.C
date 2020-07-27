#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gm, gd=DETECT;
int x,y,x1,y1;
int puncte1[6],puncte2[6],puncte3[6],puncte4[6];
initgraph(&gd,&gm,"c:\\tclite\\bgi");
rectangle(2,2,getmaxx()-2,getmaxy()-2);
line(0,0,getmaxx(),getmaxy());
line(getmaxx(),0,0,getmaxy());
x1=getmaxx()/2;
y1=getmaxy()/2;
setcolor(RED);
rectangle(x1,y1,x1+100,y1+100);
line(x1,y1,x1+100,y1+100);
line(x1,y1+100,x1+100,y1);
x=30*getmaxx()/100;
y=30*getmaxy()/100;
ellipse(x,y,0,360,60,20);
setcolor(BLUE);
circle(x,y,40);
line(x-60,y,x+60,y);
line(x,y-40,x,y+40);
setfillstyle(SOLID_FILL,RED);
puncte1[0]=x1;
puncte1[1]=y1;
puncte1[2]=x1+100;
puncte1[3]=y1;
puncte1[4]=x1+50;
puncte1[5]=y1+50;

puncte2[0]=x1;
puncte2[1]=y1;
puncte2[2]=x1;
puncte2[3]=y1+100;
puncte2[4]=x1+50;
puncte2[5]=y1+50;

puncte3[0]=x1+50;
puncte3[1]=y1+50;
puncte3[2]=x1+100;
puncte3[3]=y1+100;
puncte3[4]=x1;
puncte3[5]=y1+100;

puncte4[0]=x1+50;
puncte4[1]=y1+50;
puncte4[2]=x1+100;
puncte4[3]=y1;
puncte4[4]=x1+100;
puncte4[5]=y1+100;

while(!kbhit())
{
	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(3,puncte1);
	sector(x,y,0,90,60,20);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(3,puncte2);
	sector(x,y,90,180,60,20);
	setfillstyle(LINE_FILL,MAGENTA);
	fillpoly(3,puncte3);
	sector(x,y,180,270,60,20);
	setfillstyle(SLASH_FILL,RED);
	fillpoly(3,puncte4);
	sector(x,y,270,360,60,20);
	delay(10);

	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(3,puncte4);
	sector(x,y,90,180,60,20);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(3,puncte1);
	sector(x,y,180,270,60,20);
	setfillstyle(LINE_FILL,MAGENTA);
	fillpoly(3,puncte2);
	sector(x,y,270,360,60,20);
	setfillstyle(SLASH_FILL,RED);
	fillpoly(3,puncte3);
	sector(x,y,0,90,60,20);
	delay(10);

	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(3,puncte3);
	sector(x,y,180,270,60,20);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(3,puncte4);
	sector(x,y,270,360,60,20);
	setfillstyle(LINE_FILL,MAGENTA);
	fillpoly(3,puncte1);
	sector(x,y,0,90,60,20);
	setfillstyle(SLASH_FILL,RED);
	fillpoly(3,puncte2);
	sector(x,y,90,180,60,20);
	delay(10);

	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(3,puncte2);
	sector(x,y,270,360,60,20);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(3,puncte3);
	sector(x,y,360,90,60,20);
	setfillstyle(LINE_FILL,MAGENTA);
	fillpoly(3,puncte4);
	sector(x,y,90,180,60,20);
	setfillstyle(SLASH_FILL,RED);
	fillpoly(3,puncte1);
	sector(x,y,180,270,60,20);
	delay(random(256));
}
getch();
closegraph();
}