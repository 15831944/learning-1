program rebuturi;
const
	nmax = 100;
type
	lot = array[1..nmax] of real;
var
	n,i,nr1,nr2: integer;
	e,t: real;
   r1,r2: lot;
begin
	write('Dati numar piese din lot:');
   readln(n);
   write('Dati valorile rezistentei etalon si tolerentei:');
   readln(e,t);
   writeln('Dati valori rezistentelor din lot 1');
   for i:= 1 to n do
   begin
   	write('rezistenta',i:3,' are valoarea:');
      readln(r1[i]);
   end;
   writeln('Dati valori resistentelor din lot 2');
   for i:=1 to n do
   begin
   	write('rezistenta',i:3,' are valoarea:');
      readln(r2[i]);
   end;
   writeln;
	nr1:=0;
   for i:=1 to n do
   	if abs(r2[i]-e)/e > t then nr1:=nr1 + 1;
   nr2:=0;
   for i:=1 to n do
		if abs(r2[i]-e)/e > t then nr2:=nr2 + 1;
   if nr1 < 2 then
   	writeln('procedul 1 este mai bun')
   else
   if nr2 < 1 then
   	writeln('procedeul 2 este mai bun')
   else
   	writeln('procedeele sunt egale');
   readln;
end.
