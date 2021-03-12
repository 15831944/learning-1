program DA_NU;
const
	lungime = 80;
type
	val_indice = 1..lungime;
   sir = array[val_indice] of char;
var
	a : sir;
   numar, i : integer;
begin
	write('Introduceti sirul initial : ');
   i := 0;
   repeat
   	i := i + 1;
      read(a[i]);
   until(a[i] = '.') or (i = lungime);
   writeln;
   if (a[i] = '.')
   	then
      	numar := i - 1
      else
      	numar := i;
   for i := 1 to numar - 1 do
   	if (a[i] = 'd') and (a[i + 1] = 'a')
			then
         	begin
					a[i] := 'n';
					a[i+1] := 'u'
            end;
   write('Sirul rezultat este = ');
   for i := 1 to numar do
   	write(a[i]);
end.
