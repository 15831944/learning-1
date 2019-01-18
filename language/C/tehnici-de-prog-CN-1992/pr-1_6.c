#include<stdio.h>
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		fprintf(stderr,"Utilizare:%s/[pw]\n",argv[0]);
		exit(-1);
	}
	switch(argv[1][0])
	{
		case '/':
			switch(argv[1][1])
			{
				case 'p':
					printf("optiunea /p\n");
					break;
				case 'w':
					printf("optiunea /w\n");
					break;
				default:
					fprintf(stderr,"optiune ilegala pentru %s\n",argv[0]);
					exit(-1);
			}
			break;
		default:
			fprintf(stderr,"optiune nespecificata pentru %s\n",argv[0]);
			exit(-1);
	}
}