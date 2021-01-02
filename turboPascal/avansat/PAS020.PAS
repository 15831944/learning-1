program comun;
const
	max_elem = 10;
type
	val_indice = 1..max_elem;
	vector = array[val_indice] of integer;
var
	a,b: vector;
   na, nb, indice: val_indice;
procedure citeste_vector(var x: vector; var numar: val_indice; car: char);
var
	i: integer;
begin
	i:= 0;
   repeat
   	i:= i + 1;
      write('',car,'[',i:2,'] =');
      read(x[i]);
      if (i mod 5) = 0 then
      	writeln
   until (x[i] < 0) or (i >= max_elem);
   if x[i] < 0 then
   	numar:= i -1
   else
   	numar:= i;
   writeln;
end;

function gasit(x: vector; numar: val_indice; elem: integer): boolean;
var
	i: integer;
begin
	i:= 1;
   while(x[i] <> elem) and (i<numar) do
   	i:= i +1;
   gasit:= x[i] = elem;
end;
{ program principal }
begin
	citeste_vector(a,na,'a');
   citeste_vector(b,nb,'b');
   indice:=1;
   while not gasit(b,nb,a[indice]) and (indice <=na) do
   	indice:= indice + 1;
   if indice <= na then
   	writeln('Sirurile au elemente comune')
	else
   	writeln('Sirurile nu au elemente comune')
end.