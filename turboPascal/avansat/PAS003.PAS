program citire_1;
const
	max_elem = 10;
type
	val_indice = 1..max_elem;
   vector = array[val_indice] of integer;
var
	a: vector;
   numar_elem: integer;
   indice: val_indice;
begin
	{citire numar elemente }
   repeat
   	write('Numar elemente =');
      readln(numar_elem);
   until (numar_elem >=0) and (numar_elem <= max_elem);
   { citire elemente }
	if numar_elem > 0 then
   	begin
      	for indice:=1 to numar_elem do
            begin
             	write(' a[', indice: 2,'] = ');
               readln(a[indice]);
            end;
         {prelucrare elemente}
         {scriere rezultate}
         writeln('Rezultate');
         writeln;
         for indice:=1 to numar_elem do
         	begin
            	write(' a[',indice: 2,'] =',a[indice]: 5,';');
               if (indice mod 4) = 0 then
               	writeln;
            end;
         if (numar_elem mod 5) > 0 then
         	writeln;
      end
   else
   	writeln('Nu exista date');
end.