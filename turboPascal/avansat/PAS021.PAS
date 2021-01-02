program comun1;
const
	max_elem = 10;
type
	val_indice = 1..max_elem;
	vector = array[val_indice] of integer;
var
	a,b,c: vector;
   na,nb,indice: val_indice;
   ic: integer;

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
      	writeln;
   until (x[i] < 0) or (i >= max_elem);
	if x[i] < 0 then
   	numar:= i -1
   else
   	numar:= i;
   writeln;
end;

procedure afiseaza(x: vector; numar: val_indice);
var
	i: val_indice;
begin
	for i:= 1 to numar do
   begin
   	write(' x[',i: 2,'] =',x[i]);
      if (i mod 5) = 0 then
      	writeln;
   end;
end;

function gasit(x: vector; numar: val_indice; elem: integer): boolean;
var
	i: integer;
begin
	i:= 1;
   while (x[i] <> elem) and (i < numar) do
   	i:= i + 1;
   gasit:= x[i] = elem;
end;

procedure construieste_c;
	procedure memoreaza;
   begin
   	ic:= ic + 1;
      c[ic]:= a[indice];
   end;
begin
	ic:=0;
   for indice:= 1 to na do
   	if gasit(b,nb,a[indice]) then
      	memoreaza;
end;

{ program principal }
begin
	citeste_vector(a,na,'a');
   citeste_vector(b,nb,'b');
   construieste_c;
   writeln;
   if ic > 0 then
	   begin
   		writeln(' Elemente comune sunt:');
   	   writeln;
      	afiseaza(c,ic);
	   end
   else
   	writeln(' Nu exista elemente comune')
end.
