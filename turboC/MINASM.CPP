/*
 * exemplu de functie minim in asamblare
 */
#include <stdio.h>
#pragma inline

/* functie care calculeaza min(v1,v2) */
int vmin1(int v1, int v2)
{
	asm mov ax,v1
	asm cmp ax,v2
	asm jle min
	asm mov ax,v2
	min:return(_AX);
}

int vmin2(int v1, int v2)
{
	asm {
		mov ax,v1
		cmp ax,v2
		jle min
		mov ax, v2
	}
	min:return(_AX);
}
void main()
{
	int ret;
	ret = vmin1(10,20);
	printf("min(10,20) = %d\n", ret);
	ret = vmin2(150,30);
	printf("min(150,30) = %d\n",ret);
}