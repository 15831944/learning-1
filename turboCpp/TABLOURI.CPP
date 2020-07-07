/* tablouri de obiecte */
#include <iostream.h>
class pozitie {
	int x,y;
public:
	pozitie(int abs, int ord) {
		x = abs;
		y = ord;
		cout<<"Constructor,";
		afisare();
	}
	pozitie() {
		x = 0;
		y = 0;
		cout<<"Constructor,";
		afisare();
	}
	void deplasare(int dx, int dy) {
		x +=dx;
		y +=dy;
	}
	void afisare() {
		cout<<"x="<<x<<",y="<<y<<'\n';
	}
};
void main()
{
	//tablou static sau automatic
	pozitie tabp[10];
	//tablou alocat dinamic
	pozitie *pp = new pozitie[20];
}
