program citire_2;
const
	max_elem = 10;
type
	val_indice = 1 .. max_elem;
   vector = array[val_indice] of integer;
var
	a: vector;
   numar_elem: integer;
   indice: val_indice;
begin
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
   { prelurare elemente }
   writeln;
   writeln;
   {scrie rezultate}
   if numar_elem > 0 then
   	begin
      	writeln('Rezultate');
         writeln;
         for indice := 1 to numar_elem do
         	writeln('a[', indice: 2,'] =', a[indice]:5);
      end
   else
		write('Nu exista date');
end.