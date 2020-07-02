/*
 * functie care permite analiza continutului unui fisier oarecare prin
 * listarea pe blocuri de 256 octeti. Afisarea se face in linii de
 * 16 octeti, in doua moduri: valorile octetilor in hexa si apoi
 * interpretarea valorilor in ASCII, caracterele neafisabile se
 * inlocuiesc cu .
 */
#define N 256
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void view(char *nmf)
{
	FILE *fp;
	int i,j,k,nr,sect;
	/* tampon pentur memorarea unui bloc */
	char buf[N];
	long max;
	if (!(fp=fopen(nmf,"rb"))) {
		puts("Nu pot deschide fisierul");
		return;
	}
	/* determina lungimea fisierului */
	fseek(fp,0,SEEK_END);
	max=ftell(fp);
	/* ciclu de afisare a blocurilor solicitate de operator */
	for(;;) {
		printf("Numarul blocului de 256 bytes [>0,0=sfirsit] ");
		scanf("%d",&sect);
		fflush(stdin);
		/* terminare solicitata de operator */
		if(!sect) break;
		/* blocul nu exista in fisier */
		if ((sect -1)*N >= max) {
			puts("Sfirsit fisier !");
			continue;
		}
		/* pozitionare la inceputul blocului */
		fseek(fp, (sect -1)*N, SEEK_SET);
		nr = fread(buf,1,N,fp);
		if (!nr)
			puts("Sfirsit fisier !");
		else {
			/* afiseaza blocul, linii intregi */
			for (i=k=0; i < N/16 ;i++) {
				for(j=0; j < 16; j++, k++)
					printf("%2X ", buf[16*i+j] & 0xff);
				printf(" ");
				for(j=0; j < 16; j++)
					if(isprint(buf[16*i+j]))
						printf("%c", buf[16*i+j]);
					else
						printf(".");
				printf("\n");
			}
			/* restul ultimei linii de afisare */
			if (nr < N) {
				for(i=k,j=0; i < nr; i++, j++)
					printf("%2X ", buf[i] & 0xff);
				for(;j<16;j++)
					printf(" ");
				for(i=k; i < nr; i++)
					if(isprint(buf[i]))
						printf("%c",buf[i]);
					else
						printf(".");
				puts("\nSfirsit fisier");
			}
		}
	}
	fclose(fp);
}

void main(int argc, char * argv[])
{
	if(argc != 2) {
		printf("Apelare %s <nume.fis>\n", argv[0]);
		exit(1);
	}
	view(argv[1]);
}