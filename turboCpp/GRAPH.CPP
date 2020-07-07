/*
 * ierarhie de clase pentru desenarea in modul grafic
 */
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <string.h>
#define Linie 0
#define Bara 1
#define Disc 2
#define Text 3
struct lnod {
	void *data;
	lnod *urm;
	lnod *prec;
	lnod(void *d=0) //constructor
	{
		data = d;
		urm = prec = 0;
	}
};

//lista dublu inlantuita cu nod capat
class ldi {
protected:
	lnod cap, *crt;
public:
	ldi(); // constructor
	~ldi(); //destructor
	//test lista vida
	int nl_vida()
	{
		return &cap != cap.urm;
	}
	//initializeaza indicator curent pe nodul capat
	void capat()
	{
		crt = &cap;
	}
	//initializeaza indicator curent in fata
	void prim()
	{
		crt = cap.urm;
	}
	//initializeaza indicator curent la sfirsit
	void ultim()
	{
		crt = cap.prec;
	}
	//avanseaza indicator curent si intoarce element
	void *spre_dr();
	void *spre_st();
	//citeste elementul curent
	void *citesc();
	//adauga la dreapta nodului curent
	void *adaug_dr(void* d);
	//adauga la stinga nodului curent
	void* adaug_st(void* d);
	//extrage nodul curent
	void* extrag();
};
//constructor
ldi::ldi()
{
	crt = cap.urm = cap.prec = &cap;
}
//citire element curent
void *ldi::citesc()
{
	if(crt != &cap)
		return crt->data;
	else
		return 0;
}
//adaugare la stinga
void* ldi::adaug_st(void* d)
{
	lnod *p;
	p = new lnod(d);
	if(p) {
		p -> urm = crt;
		p -> prec = crt -> prec;
		crt -> prec = crt -> prec -> urm = p;
		crt = p;
		return p;
	}
	return 0;
}
//adaugare la dreapta
void* ldi::adaug_dr(void* d)
{
	lnod *p;
	p = new lnod(d);
	if(p) {
		p -> prec = crt;
		p -> urm = crt -> urm;
		crt -> urm = crt -> urm -> prec = p;
		crt = p;
		return p;
	}
	return 0;
}
//extrage elementul curent
void* ldi::extrag()
{
	lnod *p;
	void *d;
	if(crt != &cap) {
		p = crt;
		crt -> urm -> prec = crt -> prec;
		crt -> prec -> urm = crt -> urm;
		crt = crt -> urm;
		d = p -> data;
		delete p;
		return d;
	}
	return 0;
}
//parcurgerea in sens direct (dreapta)
void *ldi::spre_dr()
{
	if(nl_vida() && crt -> urm != &cap) {
		crt = crt -> urm;
		return crt -> data;
	}
	return 0;
}
//parcurgere in sens invers (stinga)
void* ldi::spre_st()
{
	if(nl_vida() && crt -> prec != &cap) {
		crt = crt -> prec;
		return crt -> data;
	}
	return 0;
}
ldi::~ldi()
{
	lnod *p;
	p = cap.urm;
	while (p != &cap) {
		crt = p;
		p = p -> urm;
		delete crt;
	}
}

// clasa abstracta orice figura
class fig {
protected:
	int ax, ay;// coordonate absolute
	char viz; // vizibilitate
	int ftip; //tip figura
public:
	//constructor
	fig(int ix= 0, int iy =0)
	{
		ftip = viz = 0;
		ax = ix;
		ay = iy;
	}
	virtual ~fig(); // destructor virtual
	//fixare coordonate
	void set_xy(int iax, int iay)
	{
		ax = iax;
		ay = iay;
	}
	void transl(int dx, int dy); //translatie
	//afiseaza figura pe ecran
	virtual void arata() = 0;
	//sterge figura de ecran
	virtual void ascunde() = 0;
};
//definitii metode pentru clasa fig
fig::~fig()
{
}
void fig::transl(int dx, int dy)
{
	char v = viz;
	if(v) ascunde();
	ax +=dx;
	ay +=dy;
	if(v) arata();
}

struct lin_tip { // model linie
	int s; // stil linie
	unsigned us; // stil definit de utilizator
	int g; // grosime
};
struct has_tip { //model hasurare
	int m; // model
	int c; // culoare
};
class figatr : public fig
{
protected:
	int cul; // culoare
	lin_tip lin; //linie
	has_tip has; // hasurare
public:
	//constructor
	figatr(int iax=0,int iay=0, int c=-1,int ls=-1,
		 int lg=0, int hm=-1, int hc=0);
	void set_cul(int c);
	void set_lin(const lin_tip& l);
	void set_has(const has_tip& h);
	int get_cul()
	{
		return cul;
	}
	const lin_tip& get_lin()
	{
		return lin;
	}
	const has_tip& get_has()
	{
		return has;
	}
	virtual void arata() = 0;
	virtual void ascunde() = 0;
};
figatr::figatr(int iax,int iay, int c,int ls,
		 int lg, int hm, int hc):fig(iax,iay)
{
	if(c<0) cul = getcolor();
	else cul = c;
	if(ls<0)
		getlinesettings((struct linesettingstype *)&lin);
	else {
		lin.s = ls;
		lin.g =lg;
	}
	if(hm < 0)
		getfillsettings((struct fillsettingstype *) &has);
	else {
		has.m = hm;
		has.c = hc;
	}
}
//definitii functii pentru clasa figatr
void figatr::set_cul(int c)
{
	cul = c;
	if(viz) arata();
}
void figatr::set_lin(const lin_tip& l)
{
	char v = viz;
	if(v) ascunde();
	lin = l;
	if(v) arata();
}
void figatr::set_has(const has_tip& h)
{
	char v = viz;
	if(v) ascunde();
	has = h;
	if(v) arata();
}

//linie
class linie : public figatr
{
protected:
	int x1,y1,x2,y2;
public:
	linie(int ix1, int iy1, int ix2, int iy2,
		int iax=0, int iay=0, int c=-1, int ls=-1,
		int lg=0, int hm=-1, int hc=0);
	void arata();
	void ascunde();
};
//definitii functii pentru clasa linie
linie::linie(int ix1, int iy1, int ix2, int iy2,
		int iax, int iay, int c, int ls,
		int lg, int hm, int hc):
		figatr(iax,iay,c,ls,lg,hm,hc)
{
	x1 = ix1;
	y1 = iy1;
	x2 = ix2;
	y2 = iy2;
	ftip = Linie;
}

void linie::arata()
{
	viz = 1;
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	//linie standard
	if(lin.s <5) {
		setcolor(cul);
		setlinestyle(lin.s,lin.us, lin.g);
		line(x1,y1,x2,y2);
	}
	//linie nestandard, orizontala sau verticala
	else {
		setfillstyle(has.m,has.c);
		if(y1 == y2) // linie orizontala
			bar(x1,y1-lin.g/2,x2,y2+lin.g-lin.g/2);
		if (y1 == y2)
			bar(x1-lin.g/2,y1,x2+lin.g-lin.g/2,y2);
	}
}
void linie::ascunde()
{
	viz = 1;
	setviewport(ax,ay,getmaxx(), getmaxy(), 0);
	//linie standard
	if(lin.s < 5) {
		setcolor(0);
		setlinestyle(lin.s,lin.us,lin.g);
		line(x1,y1,x2,y2);
	}
	//linie nestandard, orizontala sau verticala
	else {
		setfillstyle(0,0);
		if(y1 == y2) // linie orizontala
			bar(x1,y1-lin.g/2,x2,y2+lin.g/2-lin.g/2);
		if(y1 == y2) // linie verficala
			bar(x1-lin.g/2,y1,x2+lin.g-lin.g/2,y2);
	}
}

//deptunghi colorat, cu contur
class bara: public figatr
{
protected:
	int st, sus, dr, jos; // coordonaate relative
public:
	bara(int x1, int y1, int x2, int y2,
		int iax=0, int iay=0, int c=-1,
		int ls=-1, int lg=0,
		int hm=-1, int hc=0);
	void arata();
	void ascunde();
	//modifica dimensiune
	void set_dim(int dx, int dy);
};
//definitii functie pentru clasa bar
bara::bara(int x1, int y1, int x2, int y2,
	 int iax, int iay, int c, int ls, int lg, int hm, int hc):
	 figatr(iax,iay,c, ls, lg, hm,hc)
{
	st = x1;
	sus = y1;
	dr = x2;
	jos = y2;
	ftip = Bara;
}
void bara::arata()
{
	viz = 1;
	setcolor(cul);
	setlinestyle(lin.s, lin.us, lin.g);
	setfillstyle(has.m, has.c);
	setviewport(ax,ay, getmaxx(),getmaxy(),0);
	bar3d(st, sus, dr, jos, 0, 0);
}
void bara::ascunde()
{
	viz = 0;
	setcolor(0);
	setlinestyle(lin.s, lin.us, lin.g);
	setfillstyle(0,0);
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	bar3d(st,sus,dr,jos,0,0);
}
void bara::set_dim(int dx, int dy)
{
	char v = viz;
	if(v) ascunde();
	dr = st + dx;
	jos = sus + dy;
	if(v) arata();
}
//cerc/elipsa colorate
class disc: public figatr
{
protected:
	int xc, yc, rx, ry; //centru (relativ) si raza
public:
	disc(int ixc, int iyc, int irx, int iry=0,
		int iax=0, int iay=0,
		int c=-1, int ls=-1, int lg=0,
		int hm=-1, int hc=0);
	void arata();
	void ascunde();
	//modifca dimensiunea
	void set_dim(int nrx, int nry=0);
};
//definitii functii pentru clasa disc
disc::disc(int ixc, int iyc, int irx,int iry, int iax,
	int iay, int c, int ls, int lg, int hm, int hc):
	figatr(iax, iay, c, ls, lg, hm, hc)
{
	xc = ixc;
	yc = iyc;
	rx = irx;
	if (iry) ry = iry;
	else iry = iry;
	ftip = Disc;
}
void disc::arata()
{
	viz = 1;
	setcolor(cul);
	setlinestyle(lin.s, lin.us, lin.g);
	setfillstyle(has.m,has.c);
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	fillellipse(xc,yc,rx,ry);
}
void disc::ascunde()
{
	viz = 0;
	setcolor(0);
	setlinestyle(lin.s,lin.us,lin.g);
	setfillstyle(0,0);
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	fillellipse(xc,yc,rx,ry);
}
void disc::set_dim(int dx, int dy)
{
	char v = viz;
	if(v) ascunde();
	rx = dx;
	if (ry) ry = dy;
	else ry = dx;
	if(v) arata();
}

//atribute text
struct txt_tip
{
	int font;
	int dir;
	int dim;
	int oriz;
	int vert;
};

class text: public fig
{
protected:
	char *txt; // text
	int x,y; //pozitie relativa
	int cul; //culoare
	txt_tip atr; //atribute
public:
	text(char *s, int ix=0, int iy=0, int iax=0, int iay=0,
		int c=-1, int f=0,int dr=0,int dm=1, int ao=0,int av=0);
	~text();
	void set_cul(int c);
	void set_txt(const txt_tip& t);
	int get_cul()
	{
		return cul;
	}
	const txt_tip& get_txtatr()
	{
		return atr;
	}
	void arata();
	void ascunde();
};
//definitii functii pentru clasa text
text::text(char *s, int ix, int iy, int iax, int iay, int c,
	int f, int dr, int dm, int ao, int av): fig(iax,iay)
{
	ftip = Text;
	x = ix;
	y = iy;
	txt = new char[strlen(s) + 1]; //text + '\0'
	strcpy(txt,s);
	if(c<0) cul = getcolor();
	else cul = c;
	atr.font = f;
	atr.dir = dr;
	atr.dim = dm;
	atr.oriz = ao,
	atr.vert = av;
}
text::~text()
{
	delete txt;
}
void text::set_cul(int c)
{
	char v = viz;
	if(v) ascunde();
	setcolor(c);
	if(v) arata();
}
void text::set_txt(const txt_tip& t)
{
	char v = viz;
	if(v) ascunde();
	atr = t;
	if(v) arata();
}
void text::arata()
{
	viz = 1;
	setcolor(cul);
	settextstyle(atr.font, atr.dir,atr.dim);
	settextjustify(atr.oriz,atr.vert);
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	outtextxy(x,y,txt);
}
void text::ascunde()
{
	viz = 0;
	setcolor(0);
	settextstyle(atr.font, atr.dir, atr.dim);
	settextjustify(atr.oriz, atr.vert);
	setviewport(ax,ay,getmaxx(),getmaxy(),0);
	outtextxy(x,y,txt);
}

class imldi: public fig, public ldi
{
public:
	void arata();
	void ascunde();
	void transl(int dx, int dy);
};
//definitii functii pentru clasa imldi
void imldi::arata()
{
	viz = 1;
	for(crt = cap.urm; crt != &cap; crt = crt -> urm)
	((fig *)crt -> data) -> arata();
}
void imldi::ascunde()
{
	viz  = 0;
	for(crt = cap.urm; crt != &cap; crt = crt -> urm)
		((fig *)crt -> data) -> ascunde();
}
void imldi::transl(int dx, int dy)
{
	char v = viz;
	if(v) ascunde();
	for(crt = cap.urm; crt != &cap; crt = crt -> urm)
		((fig *)crt -> data) -> fig::transl(dx,dy);
	if(v) arata();
}
void main()
{
	int gdrv = VGA, gmod = VGAHI;
	initgraph(&gdrv, &gmod, "H:\\BORLANDC\\BGI");
	int mx = getmaxx();
	int my = getmaxy();
	int dx = (mx +1)/2 -mx/5;
	int dy = (my +1)/2 -my/5;
	//atribute implicite
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setfillstyle(EMPTY_FILL,0);
	//bara cu atribute implicite
	bara b1(0,0,mx,my);
	//bara cu atribute specificate, obiect dinamic
	bara *b2 = new bara(0,0,dx,dy,mx/10,my/10, GREEN, SOLID_LINE,
		 THICK_WIDTH, HATCH_FILL, MAGENTA);
	//alte atribute implicite
	setcolor(BLUE);
	setfillstyle(INTERLEAVE_FILL, MAGENTA);
	//cerc cu atribute implicite, obiect dinamic
	disc *d1 = new disc(0,0,dy/2, dy/2, 3*mx/4,my/4);
	//elipsa, obiect dinamic
	disc* d2 =  new disc(0,0,dx/2,dy/2,mx/4,3*my/4,CYAN, SOLID_LINE,
		THICK_WIDTH, XHATCH_FILL, MAGENTA);
	//line cu atribute implicite
	linie* l1 = new linie(mx/10, my/10, dx, my/10, mx/2, my/2);
	//linie cu atribute specificate
	linie* l2 = new linie(mx/10,my/10,dx,2*my/10,mx/2,my/2, RED,
		DASHED_LINE, NORM_WIDTH);
	//linie desenata ca bara cu 4 pixeli latime
	linie* l3 = new linie(mx/10,my/10,dx,2*my/10,mx/2,my/2, RED,5,4);
	//text
	text* txt = new text("Doar un test",mx/2,my-5,0,0,YELLOW,
		TRIPLEX_FONT, HORIZ_DIR,3);
	//ansamblu
	imldi img;
	img.adaug_dr(b2);
	img.adaug_dr(d1);
	img.adaug_dr(d2);
	img.adaug_dr(l1);
	img.adaug_dr(l2);
	img.adaug_dr(l3);
	img.adaug_dr(txt);
	//afisare
	b1.arata();
	getch();
	img.arata();
	getch();
	cleardevice();
	while(!kbhit()) {
		img.ascunde();
		delay(300);
		img.arata();
		delay(300);
	}
	getch();
	getch();
	//extrage si elimina obiectele din lista
	img.prim();
	fig* fp;
	while((fp=(fig *)img.extrag())) {
		fp -> ascunde();
		delete fp;
		getch();
	}
	closegraph();
}