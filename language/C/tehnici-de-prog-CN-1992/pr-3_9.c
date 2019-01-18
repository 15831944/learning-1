#include<stdio.h>
void prim(register char *plinie[])
{
	register char *pc;
	while(pc=*plinie++)
	{
		while(*pc++!='.');
		*pc='\0';
	}
}
main()
{
	static char *linii[]={
		"Prima propozitie.Ea contine: L 17 caractere.",
		"A doua propozitie.Ea contine: L 18 caractere.",
		"A treia propozitie. Ea contine: L 19 caractere.",
		(char *)NULL };
	int i;
	prim(linii);
	for(i=0;linii[i];i++) printf("%s\n",linii[i]);
}
