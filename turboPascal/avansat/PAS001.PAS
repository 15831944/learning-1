program vinzare;
uses CRT;
const
	max_oferte = 10;
type
	numar_oferte = 0 .. max_oferte;
   val_indice = 1 .. max_oferte;
   vector_oferte = array[val_indice] of integer;
var
	pret_oferit, pret_acceptat: real;
   numar_acceptat, numar_oferta: integer;
   lista_oferta: vector_oferte;
   pozitie_lista: numar_oferte;
begin
	numar_acceptat:= 0;
   pozitie_lista:=0;
	write('Pret minim: ');
   readln(pret_acceptat);
   numar_oferta:=1;
	{citire prima oferta}
   clrscr;
   write('Ce pret oferiti?');
   readln(pret_oferit);
   while pret_oferit > 0 do
   begin
   	{ oferta curenta este la fel de buna ca cea veche ? }
      if  pret_oferit = pret_acceptat then
	      begin
   	   	pozitie_lista:=pozitie_lista + 1;
      	   lista_oferta[pozitie_lista]:=numar_oferta;
	      end;
      { oferta curenta este mai buna decit cea veche ?}
      if (pret_oferit > pret_acceptat) then
      	begin
         	pret_acceptat:=pret_oferit;
            pozitie_lista:=1;
            lista_oferta[pozitie_lista]:=numar_oferta;
         end;
      { citire oferta urmatoare }
      clrscr;
      numar_oferta:=numar_oferta + 1;
      write('Ce pret oferiti ?');
      readln(pret_oferit);
   end;
   { afisare rezultate }
   clrscr;
   case pozitie_lista of
   0: writeln('Nu exista oferte interesante');
   1: writeln('Pretul maxim (', pret_acceptat:1:0,') a fost ',
   		'oferit de cumparatorul ', lista_oferta[1])
   else
   	begin
      	writeln('Pret maxim oferit = ', pret_acceptat:1:0);
         writeln('Se face alegerea intre ofertele:');
         for numar_oferta:=1 to pozitie_lista do
         	write(lista_oferta[numar_oferta]:5,' ');
         writeln;
      end
   end; { case}
   readln;
end.