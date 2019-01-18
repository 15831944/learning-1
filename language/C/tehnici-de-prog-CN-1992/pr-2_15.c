#include<stdio.h>
#include<string.h>
char buf[]="mesaj";
char *p="sir_vechi";
main()
{
	char *q="sir";
	printf("adresa buf: %x\n",buf);
	printf("adresa q: %x\n",&q);
	printf("adresa p: %x\n",&p);
	printf("continut \t\t lungime \t\t adresa\n");
	printf("%s\t\t\t %d \t\t\t %x\n",buf,strlen(buf),buf);
	printf("%s\t\t\t %d \t\t\t %x\n",p,strlen(p),p);
	printf("%s\t\t\t %d \t\t\t %x\n",q,strlen(q),q);
	p="sir_nou";
	buf[2]='n';
	printf("%s\t\t\t %d \t\t\t %x\n",buf,strlen(buf),buf);
	printf("%s\t\t\t %d \t\t\t %x\n",p,strlen(p),p);
}