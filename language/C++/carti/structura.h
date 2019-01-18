//definirea structurii asupra careia se face referire
#define load_struct
struct structura
{
	int intreg;
	char *nume;
	structura(){}
	void initializare(int arg1,char *arg2){intreg=arg1;nume=arg2;}
};
