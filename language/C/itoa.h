void itoa(int value,char *str,int base)
{
volatile int i;
volatile int value1;
volatile int j;
volatile int flag;
	j=0;
	if(value<0)
	{
		value=-value;
		str[j]='-';
		j++;
	}
	flag=1;
	for(i=1000000000;i>0;i=i/10)
	{
		value1=value/i;
		if((value1==0)&&(flag==0))
		{
			str[j]='0';
			j++;
			value=value-value1*i;
		}
		if(value1!=0)
		{
			flag=0;
			str[j]=(char)(value1+48);
			j++;
			value=value-value1*i;
		}
	}
}
