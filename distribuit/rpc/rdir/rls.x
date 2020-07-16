/*
 * rls.x protocol de ls la distanta
 */
const MAXNAMELEN = 512;
typedef string nametype < MAXNAMELEN >; /* o intrare in director */
typedef struct namenode *namelist; /* legatura in liniile rezumatului */
/*
 * un nod in director
 */
struct namenode {
	nametype name;
	namelist pNext;
};
/*
 * rezultatul operatiei READDIR
 */
union readdir_res switch (int errno) {
	case 0:namelist list; /* intoarce rezumatul directorului */
default:
		void; /* Eroare: nu intoarce nimic */
};
/*
 * Definitia programului de rezumat la distanta
 */
program DIRPROG {
	version DIRVERS {
		readdir_res
		READDIR(nametype) = 1;
	} = 1;
} = 0x20000001;	
		