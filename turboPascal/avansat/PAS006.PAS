program ord_2;
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
   ord_cresc, ord_desc: boolean;
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
	{ prelucrare elemente }
   ord_cresc:= true;
   ord_desc:= false;
   indice:= 1;
   while (ord_cresc xor ord_desc) and (indice < numar_elem) do
   begin
   	if ord_cresc and (a[indice] > a[indice +1]) then
      begin
      	ord_cresc:= false;
         if indice = 1 then
         	ord_desc:= true
      end;
      if not ord_cresc and (a[indice] < a[indice +1]) then
      	ord_desc:= false;
      indice:= indice +1;
   end;
   { scrie rezultate }
   if numar_elem > 0 then
   begin
   	if ord_desc or ord_cresc then
      begin
      	write('Sirul este ordonat ');
         if ord_cresc then
         	writeln('crescator')
         else
         	writeln('descrescator')
      end
   	else
      	writeln('Sirul nu este ordonat');
   end
   else
   	writeln('Nu exista date')
end.