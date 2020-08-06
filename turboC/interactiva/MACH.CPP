/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * tehnici de machetare a ecranului
 */
#include <stdio.h>
#include <ctype.h>
#include <bios.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

static struct mach
{
	char *denc[NC];
	int coord[NC][2];
	int lg[NC];
	int k;
	int col;
} mach = {
	{
		"ART.NR:", "CODUL:", "DENUMIREA:", "UM:", "PRET:",
		"CANT. PROGRAMATA.:", "CANT. REALIZATA.:", " "
	},
	{
		{60 ,3}, /* nr. art. */
		{15,10}, /* cod. prod. */
		{17,15},{50,15}, /* den + um */
		{20,17},	/* pret */
		{22,19}, /* programat */
		{24,21} /* realizat */
	},
	{3,3,16,4,8,10,10}
};

struct ecran
{
	struct car
	{
		char c;
		char a;
	} e[25][80];
};

struct ecran far *pv = (struct ecran far*)0xB8000000;
#define pg pv->e
unsigned char norm = (WHITE<<4) | BLUE, inv = (BLUE<<4) | WHITE;

void mesaj(char *mes)
{
	void *zona;
	struct text_info scrpar;
	gettextinfo(&scrpar);
	window(2,22,79,23);
	zona = malloc(2*2*80);
	gettext(2,22,79,23,zona);
	textcolor(RED);
	textbackground(LIGHTGRAY);
	clrscr();
	cprintf("%40s",mes);
	getch();
	textattr(scrpar.attribute);
	puttext(2,22,79,23,zona);
	free(zona);
	window(scrpar.winleft, scrpar.wintop, scrpar.winright, scrpar.winbottom);
	gotoxy(scrpar.curx,scrpar.cury);
}

/* functia pentru scriere texte */
void scrtxt(char *ps, int l, int c, unsigned char at)
{
	int i = 0;
	for(;ps[i] !='\0'; i++, c++)
	{
		pg[l-1][c-1].c = ps[i];
		pg[l-1][c-1].a = at;
	}
}
/* afisare denumiri cimpuri */
void desenm()
{
	int nr = 0;
	while(strlen(mach.denc[nr]))
	{
		gotoxy(mach.coord[nr][0],mach.coord[nr][1]);
		cputs(mach.denc[nr]);
		mach.coord[nr][0] = wherex()+1;
		mach.coord[nr][1] = wherey();
		nr++;
	}
}
/* umplerea cu spatii a machetei */
void fill(int tot)
{
	int i,j;
	for(j = tot ?  0:1; j<=KMAX; j++)
		for(i = mach.coord[j][0]; i < mach.coord[j][0]+mach.lg[j];i++)
		{
			int tmp = mach.coord[j][1]-1;
			pg[tmp][i-1].c=' ';
			pg[tmp][i-1].a= ( BLUE <<4) | (WHITE);
		}
}

/* scrie numarul articolului curent */
void scrnrart(int nr)
{
	gotoxy(mach.coord[0][0],mach.coord[0][1]);
	cprintf("%3.3d",nr);
	gotoxy(mach.coord[1][1],mach.coord[1][1]);
	mach.k = 1;
	mach.col = mach.coord[1][0];
}
/* cadrare cimpuri numerice */
void rearanj()
{
	int k = mach.k;
	int s = mach.lg[k] + mach.coord[k][0] -1, j, vb = 0;
	if (k != 0)
		for(j = mach.coord[k][0];j < s; j++)
			if(pg[mach.coord[k][1] -1][j-1].c != ' ')
			{
				vb = 1;
				break;
			}
	if (vb == 1)
		while(pg[mach.coord[k][1] -1][s-1].c == ' ')
		{
			for(j=s; j>mach.coord[k][0];j--)
				pg[mach.coord[k][1]-1][j-1].c = pg[mach.coord[k][1] -1][j-2].c;
			pg[mach.coord[k][1]-1][mach.coord[k][0]-1].c=' ';
		}
}
/* introduce caracter prin suprascriere */
void overwrite(char ca)
{
	int k = mach.k;
	void down();
	pg[mach.coord[k][1]-1][mach.col-1].c = ca;
	mach.col +=1;
	if(mach.col> mach.coord[k][0]+mach.lg[k]-1)
		down();
	else
		gotoxy(mach.col,mach.coord[k][1]);
}
/* introduce caracter prin insertie */
void insert(char ca)
{
	void down();
	int k = mach.k, lin;
	int i,s;
	s = mach.coord[k][0]+mach.lg[k]-1;
	lin = mach.coord[k][1];
	for(i=s;i>mach.col;i--)
		pg[lin-1][i-1].c = pg[lin-1][i-2].c;
	pg[lin-1][mach.col-1].c = ca;
	mach.col +=1;
	if(mach.col> s)
		down();
	else
		gotoxy(mach.col,lin);
}
/* stergere caracter */
void del()
{
	int lin, s,h,k = mach.k;
	s = mach.coord[k][0]+mach.lg[k]-1;
	lin = mach.coord[mach.k][1];
	for(h = mach.col;h<s;h++)
		pg[lin-1][h-1].c = pg[lin-1][h].c;
	pg[lin-1][s-1].c = ' ';
}
/* trece la cimp precedent-sageata sus */
void up()
{
	if(mach.k == 1)
		printf("\a");
	else
	{
		rearanj();
		mach.k -= 1;
		mach.col=mach.coord[mach.k][0];
		gotoxy(mach.col,mach.coord[mach.k][1]);
	}
}
/* trece la cimpul urmator - sageata jos */
void down()
{
	int k = mach.k;
	if(k == KMAX)
		printf("\a");
	else
	{
		rearanj();
		mach.k +=1;
		k = mach.k;
		mach.col = mach.coord[k][0];
		gotoxy(mach.coord[k][0],mach.coord[k][1]);
	}
}
/* mutarea cursor dreapta */
void right()
{
	mach.col +=1;
	if(mach.col>mach.coord[mach.k][0]+mach.lg[mach.k]-1)
		if(mach.k == KMAX)
		{
			printf("\a");
			mach.col -=1;
		}
		else
		{
			rearanj();
			mach.k +=1;
			mach.col = mach.coord[mach.k][0];
			gotoxy(mach.col,mach.coord[mach.k][1]);
		}
	else
		gotoxy(mach.col,mach.coord[mach.k][1]);
}
/* mutarea cursor stinga */
void left()
{
	mach.col -=1;
	if(mach.col < mach.coord[mach.k][0])
		if(mach.k == 1)
		{
			printf("\a");
			mach.col +=1;
		}
		else
		{
			rearanj();
			mach.k -=1;
			mach.col = mach.coord[mach.k][0]+mach.lg[mach.k]-1;
			gotoxy(mach.col,mach.coord[mach.k][1]);
		}
	else
		gotoxy(mach.col,mach.coord[mach.k][1]);
}
/* tratare tasta insert */
void ins(int *cont)
{
	(*cont) = !(*cont);
	if(*cont)
		scrtxt("TYPEOVER",25,61,norm);
	else
		scrtxt("INSERT  ",25,61, inv);
}
/* tratare tasta CR */
void cr(int *nr, struct articol *art, FILE *fp)
{
	char c[NC][20];
	int i,j,z;
	float temp;
	if(mach.k == KMAX)
	{
		for(j=1;j<=KMAX;j++)
		{
			for(z=0, i=mach.coord[j][0];i<mach.coord[j][0]+mach.lg[j];i++,z++)
				c[j-1][z]=pg[mach.coord[j][1]-1][i-1].c;
			c[j-1][z]='\0';
			/* mesaj(c[j-1]); */
		}
		sscanf(c[0],"%3d",&art->cod);
		if(art->cod > 0 && art->cod < 200)
		{
			sscanf(c[1],"%16s",art->den);
			sscanf(c[2],"%4s",art->um);
			sscanf(c[3],"%8f",&temp);
			art->pret = temp;
			sscanf(c[4],"%10f",&temp);
			art->progr=temp;
			sscanf(c[5],"%10f",&temp);
			art->realiz = temp;
			fseek(fp,(long)((art->cod-1)*sizeof(struct articol)),SEEK_SET);
			fwrite(art,sizeof(struct articol),1,fp);
			mach.k = 0;
			mach.col = mach.coord[mach.k][0];
			*nr+=1;
			scrnrart(*nr);
			fill(0);
		}
		else
			mesaj("Cod in afara intervalului!");
	}
	else
	{
		rearanj();
		mach.k +=1;
		mach.col=mach.coord[mach.k][0];
		gotoxy(mach.col,mach.coord[mach.k][1]);
	}
}
/* prelucrare CTRL/Z */
void ctrlz(FILE *pf)
{
	fclose(pf);
	textattr(0x07);
	clrscr();
}
