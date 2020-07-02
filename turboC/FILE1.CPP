/*
 * programul copiaza datele din fisierul in.txt
 * din directorul curent in fisierul nou create
 * afs.txt
 * de remarcat ca fiind fisier binar nu se poate testa EOF
 * se utilizeaza feror() si cu if ca altfel se pune EOF in destinatie
 */
#include <stdio.h>
void main()
{
	FILE *fps, *fpd;
	char c;
	if ((fps = fopen("in.txt","rb")) == NULL) {
		puts("Nu pot deschide fisierul sursa !");
		return;
	}
	if ((fpd = fopen("afs.txt","wb")) == NULL) {
		puts("Nu pot create fisierul destinatie !");
		return;
	}
	while(!feof(fps)) {
		c = getc(fps);
		if (!feof(fps))
			putc(c,fpd);
	}
	fclose(fps);
	fclose(fpd);
}