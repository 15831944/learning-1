/*
 *exemplu din Grafica interactiva pe calculatoare personale
 * de Ion Smeurenu, Daniel Luca, MArian Dardala, Ioan Oagescu
 * Felix Furtuna editura Militara, Bucuresti 1995
 */
/*
 * umplerea unui polinom
 */
#include <conio.h>
#include <stdio.h>
#include <alloc.h>
#include <graphics.h>
#include <process.h>

struct lista
{
	int y;
	float x,dx;
	struct lista *next;
};
int (*Introd_Date(int *m))[2]
{
	int i, (*a)[2];
	printf("\n Nr de virfuri=");
	scanf("%d",m);
	a = (int (*)[2]) malloc((*m)*2*sizeof(int));
	for(i = 0; i< *m;i++)
	{
		printf("\nCoord x a punctului %d=",i+1);
		scanf("%d",&a[i][0]);
		printf("\nCoord y a punctului %d=",i+1);
		scanf("%d",&a[i][1]);
	}
	return a;
}
struct lista **CreateET(int (*a)[2],int& ymin,int& ymax,int n)
{
	int p1[2],p2[2];
	int (*q)[2],i,j,m,d=DETECT;
	float z;
	struct lista **et,*tmp;
	q = (int (*)[2])malloc((n+1)*2*sizeof(int));
	for(i = 0; i < n; i++)
	{
		q[i][0] = a[i][0];
		q[i][1] = a[i][1];
	}
	q[n][0] = a[0][0];
	q[n][1] = a[0][1];
	initgraph(&d,&m,"H:\\BORLANDC\\BGI");
	ymin = getmaxy();
	ymax = 0;
	setcolor(BLUE);
	et = (struct lista **)malloc((ymin+1)*sizeof(struct lista *));
	for(i = 0; i <= ymin;i++)
		et[i] = NULL;
	for(i = 1; i<= n;i++)
	{
		line(q[i-1][0],q[i-1][1],q[i][0],q[i][i]);
		if(q[i-1][1]>q[i][1])
		{
			p1[0] = q[i][0];
			p1[1] = q[i][1];
			p2[0] = q[i-1][0];
			p2[1] = q[i-1][1];
		}
		else
		{
			p1[0] = q[i-1][0];
			p1[1] = q[i-1][1];
			p2[0] = q[i][0];
			p2[1] = q[i][1];
		}
		if (p1[1] < p2[1])
		{
			z = (float)(p2[0] - p1[0])/(float)(p2[1] - p1[1]);
			tmp = (struct lista*)malloc(sizeof(struct lista));
			tmp -> y = p2[1];
			tmp -> x = p1[0];
			tmp -> dx = z;
			tmp -> next = et[p1[1]];
			et[p1[1]] = tmp;
			if (ymin > p1[1])
				ymin = p1[1];
			if (ymax < p2[1])
				ymax = p2[1];
		}
	}
	free(q);
	return et;
}
void Modific(struct lista **l, int i, struct lista **et)
{
	struct lista *crt, *ant;
	crt = *l;
	while(crt != NULL && crt ->y == i)
		crt = crt->next;
	*l = crt;
	if (crt != NULL)
	{
		crt -> x = crt -> x + crt -> dx;
		ant = *l;
		crt = (*l) -> next;
	}
	while(crt != NULL)
	{
		if (crt -> y == i )
			ant -> next = crt -> next;
		else
		{
			ant = crt;
			crt -> x = crt -> x + crt -> dx;
		}
		crt = crt -> next;
	}
	if (*l == NULL)
		*l = et[i];
	else
		ant -> next = et[i];
}

void Trasare_Scan(struct lista *aet, int i)
{
	int x1, x2;
	struct lista *crt;
	crt  = aet;
	while( crt != NULL)
	{
		x1 = crt -> x;
		crt = crt -> next;
		x2 = crt -> x;
		crt = crt -> next;
		line(x1,i,x2,i);
	}
}
struct lista *Sort(struct lista *l)
{
	int k;
	struct lista *a1,*a2, *a3;
	if (l == NULL)
	{
		printf("\n Lista vida!!");
		exit(1);
	}
	if (l -> next == NULL)
	{
		printf("\n Lista cu un singur articol !!");
		return l;
	}
	k = 0;
	while(k == 0)
	{
		k = 1;
		if (l -> x > l -> next -> x)
		{
			a1 = l;
			l = l -> next;
			a1 -> next = l -> next;
			l -> next = a1;
			k =0;
		}
		a1 = l;
		a2 = l -> next;
		a3 = l -> next -> next;
		while (a3 != NULL)
		{
			if (a2 -> x > a3 -> x)
			{
				k = 0;
				a2 -> next = a3 -> next;
				a3 -> next = a2;
				a1 -> next = a3;
				a1 = a3;
				a2 = a2 -> next;
			}
			else {
				a1 = a1 -> next;
				a2 = a2 -> next;
				a3 = a3 -> next;
			}
		}
	}
	return l;
}
void ProcessET(struct lista **et, int ymin, int ymax)
{
	struct lista *aet = NULL;
	setcolor(RED);
	for (int i = ymin; i < ymax; i++)
	{
		Modific(&aet,i,et);
		aet = Sort(aet);
		Trasare_Scan(aet,i);
	}
}
void main(void)
{
	int ymin, ymax, n, (*a)[2];
	struct lista **et;
	clrscr();
	a = Introd_Date(&n);
	et = CreateET(a, ymin, ymax, n);
	ProcessET(et, ymin, ymax);
	getch();
	closegraph();
}