#include<math.h>
#include<stdio.h>
main()
{
	struct ftrig
	{
		char *numef;
		double (*ptrf)();
	};
	static struct ftrig tabl[10]={"acos",acos,"asin",asin,"atan",atan,"atan2",atan2,"cos",cos,"cosh",cosh,"sin",sin,"sinh",sinh,"tan",tan,"tanh",tanh};
	int i;
	for(i=0;i<10;i++) printf("%04x\t%s\n",tabl[i].ptrf,tabl[i].numef);
}