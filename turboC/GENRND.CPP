/* fisierul genrnd.cpp */
#include <time.h>
/* include genrnd.h aflat in directorul curent */
#include "genrnd.h"

static va_t va = 98761234;
/* genrator pseudoaleator */
va_t vaunf(void)
{
	va = (A*va+C)%M;
	return va;
}
/* funtia de initializare */
void vainit(void)
{
	va = time(0);
}