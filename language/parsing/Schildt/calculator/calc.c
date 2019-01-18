#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
char *prog;
void eval_exp(double *rezultat);
int main(void)
{
	double rezultat;
	char *p;
	
	p=malloc(100);
	if(!p)
	{
		printf("Eroare de alocare.\n");fflush(stdout);
		exit(1);
	}
	/* proceseaza expresiile pina la introducerea unui rind gol */
	do
	{
		prog=p;
		printf("Introduceti expresia: ");fflush(stdout);
		gets(prog);
		if(!prog) break;
		eval_exp(&rezultat);
		printf("Rezultatul este: %.2f\n",rezultat);
		fflush(stdout);
	} while(*p);
}