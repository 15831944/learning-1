#define N 10
typedef struct
{
	int g;
	int v;
} OBIECT;
OBIECT a[N]={ 10,18,11,20,12,17,13,19,4,25,15,21,16,27,7,23,8,25,19,24};
int glim; //greutatea limita a unui set
int maxv; //valoarea maxima a obiectelor din set
char s[N];	//sirul obiectelro selectate
char opts[N];	//sirul optim de obiecte selectate
incerc(int i,int gt,int av)
/*
	i 	-index in lista obiectelro
	gt	-greutatea curenta a obiectelro dins et
	av	-valoarea totala a obeictelro neincluse in set
*/
{
	int av1;
	if((gt+a[i].g) <= glim)
	{
		s[i]='*';
		if(i<N-1) incerc(i+1,gt+a[i].g,av);
		else if(av>maxv)
		{
			int i;
			maxv=av;
			for(i=0;i<N;i++) opts[i]=s[i];
		}
		s[i]=' ';
	}
	av1=av-a[i].v;
 if(av1>maxv) if(i<N-1) incerc(i+1,gt,av1);
 else
 {
 	 int i;
	 maxv=av1;
	 for(i=0;i<N;i++) opts[i]=s[i];
 }
}
void main()
{
	int totv=maxv=0;
	int i,g;
	for(i=0;i<N;i++) totv+=a[i].v;
	printf("Greutate |");
	for(i=0;i<N;i++) printf("%4d",a[i].g);
	printf("\n Valoare |");
	for(i=0;i<N;i++) printf("%4d",a[i].v);
	printf("\n--------------------------");
	printf("---------------------------\n");
	for(g=glim=10;g<=120;g=glim+=10)
	{
		printf("%7d|",g);
		incerc(0,0,totv);
		for(i=0;i<N;i++) printf("%4c",opts[i]);
		printf("\n");
	}
	printf("----------------------------");
	printf("---------------------------\n");
}
