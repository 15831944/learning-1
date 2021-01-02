program ord_1;
const
	max_elem = 10;
type
   val_numar_elemente = 0..max_elem;
   val_indice = 1..max_elem;
   vector = array[val_indice] of integer;
var
   a: vector;
   numar_elem: val_numar_elemente;
   indice: val_indice;
   este_ordonat: boolean;
begin
{citire elemente}
   indice:= 1;
   repeat
   	write('a[',indice:2,'] = ');
      read(a[indice]);
      indice:= indice + 1;
   until (a[indice -1] < 0) or (indice > max_elem);
   if a[indice -1] < 0 then
   	numar_elem := indice -2
	else
   	numar_elem := indice -1;
	{ prelucrare elemente}
   este_ordonat := true;
   indice:= 1;
	while este_ordonat and (indice < numar_elem) do
   	begin
      	este_ordonat := a[indice] <=a[indice+1];
         indice:= indice +1
      end;
   { scrie rezultate }
   if numar_elem > 0 then
   	begin
      	write('Sirul ');
         if not este_ordonat then
         	write('nu ');
         writeln('este ordonat crescator')
      end
   else
   	writeln('Nu exista date')
end.
