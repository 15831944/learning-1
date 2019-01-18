#include<stdio.h>
#define ROSU 1
#define GALBEN 2
#define ALBASTRU 4

void main()
{
	int i;
	for(i=1;i<8;i++)
	switch(i)
	{
		case ROSU:
			printf("rosu\n");
			break;
		case GALBEN:
			printf("galben\n");
			break;
		case ALBASTRU:
			printf("albastru\n");
			break;
		case ROSU+GALBEN:
			printf("portocaliu\n");
			break;
		case ROSU+ALBASTRU:
			printf("violet\n");
			break;
		case ALBASTRU+GALBEN:
			printf("verde\n");
			break;
		default:
			printf("Culoare necunoscuta\n");
	}
}