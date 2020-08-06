/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * pseudoanimatie a unei biciclete
 * pedala isi schimba pozitia pe parcursul deplasarii
 */
#include <graphics.h>
#include <alloc.h>
#include <dos.h>
#include <conio.h>
#define STEP 5
void *ob1,*ob2,*ob3,*ob4;
void drawob(void);
void moveob(void);
void main()
{
	int gmode, gdriver = DETECT;
	initgraph(&gdriver, &gmode, "H:\\BORLANDC\\BGI");
	setcolor(RED);
	drawob();
	getch();
	moveob();
	getch();
	closegraph();
}

void drawob(void)
{
	void *ped;
	circle(50,100,25);
	circle(150,100,25);
	line(50,100,80,85);
	line(80,85,134,85);
	line(77,82,95,100);
	line(130,80,150,100);
	line(128,80,113,82);
	line(128,80,116,78);
	line(72,81,89,81);
	line(73,82,90,82);
	ob1 = malloc(imagesize(25,75,175,125));
	ob2 = malloc(imagesize(25,75,175,125));
	ob3 = malloc(imagesize(25,75,175,125));
	ob4 = malloc(imagesize(25,75,175,125));
	ped = malloc(imagesize(85,90,110,110));
	circle(95,100,5);
	line(95,100,136,87);
	getimage(85,90,110,110,ped);
	line(86,100,104,100);
	line(85,100,87,100);
	line(103,100,105,100);
	getimage(25,75,175,125,ob1);
	putimage(85,90,ped,COPY_PUT);
	line(88,96,102,104);
	line(87,96,89,96);
	line(101,104,103,104);
	getimage(25,75,175,125,ob2);
	putimage(85,90,ped,COPY_PUT);
	line(95,95,95,105);
	line(94,95,96,95);
	line(94,105,96,105);
	getimage(25,75,175,125,ob3);
	putimage(85,90,ped,COPY_PUT);
	line(102,96,88,104);
	line(101,96,103,96);
	line(87,104,89,104);
	getimage(25,75,175,125,ob4);
	free(ped);
}
void moveob(void)
{
	int i,c;
	for(i = 0, c =0; i < getmaxx()-200; i+=STEP,c++)
	{
		switch(c%4)
		{
			case 0:
				putimage(25+i,75,ob4,XOR_PUT);
				putimage(25+STEP+i,75,ob1,XOR_PUT);
				break;
			case 1:
				putimage(25+i,75,ob1,XOR_PUT);
				putimage(25+STEP+i,75,ob2,XOR_PUT);
				break;
			case 2:
				putimage(25+i,75,ob2,XOR_PUT);
				putimage(25+STEP+i,75,ob3,XOR_PUT);
				break;
			case 3:
				putimage(25+i,75,ob3,XOR_PUT);
				putimage(25+STEP+i,75,ob4,XOR_PUT);
				break;
		}
		delay(20);
	}
}