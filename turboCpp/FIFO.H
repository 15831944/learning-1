/* fisierul fifo.h declaratia clasei fifo */
class fifo { // lista fIFO de nmax numere intregi
	int nmax; //dimensiunea listei
	int *tab; //adresa tabloului listei
	int ncrt; //numarul curent de elemente din lista
	int prim; //indexul primului element
public:
	fifo(int=100); // constructor
	fifo(fifo &); //constructor copiere
	~fifo(); //destructor
	int adaug(int); //aduga un element la sfirsit
	int extrag(int &); // extrage primul element
	//metode inline
	int nl_vida() { //not lista vida
		return ncrt > 0; //ncrt == 0 -> lista vida
	}
	int nl_plina() { // not lista plina
		return ncrt < nmax; // ncrt == nmax -> lista plina
	}
};

