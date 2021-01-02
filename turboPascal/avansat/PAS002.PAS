program vinzare_2;
uses CRT;
const
	max_oferte = 10;
type
	val_indice = 1..max_oferte;
   vector_oferte = array[val_indice] of integer;
var
	cod_oferta,val_oferta: vector_oferte;
   indice: val_indice;
   i, numar_oferte, aux: integer;
	lista_ordonata: boolean;
begin
	i:=0;
   {citire date}
   repeat
   	i:=i+1;
      clrscr;
      write('Ce cod aveti?');
      readln(cod_oferta[i]);
      write('Ce pret aveti?');
      readln(val_oferta[i]);
   until((val_oferta[i] <= 0) or (i >= max_oferte));
	{ determina numar oferte utile }
   if val_oferta[i] <= 0 then
   	numar_oferte:=i-1
   else
   	numar_oferte:=i;
   { ordonare dupa valoare oferta }
   repeat
   	lista_ordonata:=true;
      for indice:=1 to numar_oferte-1 do
      	if val_oferta[indice] < val_oferta[indice+1] then
				begin
            	aux:=val_oferta[indice];
               val_oferta[indice]:=val_oferta[indice+1];
               val_oferta[indice+1]:=aux;
               aux:=cod_oferta[indice];
               cod_oferta[indice]:=cod_oferta[indice+1];
               cod_oferta[indice+1]:=aux;
               lista_ordonata:=false;
            end
   until lista_ordonata;
   {afisare rezultata}
   clrscr;
   writeln('Cod oferta  Valoare oferta');
   for i:=1 to 28 do write('=');
   writeln;
   for indice:=1 to numar_oferte do
   	writeln(cod_oferta[indice]: 6, val_oferta[indice]: 17);
   for i:=1 to 28 do write('=');
   writeln;
end.