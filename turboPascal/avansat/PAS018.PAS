program testproc2;
var
	n, nr1,nr2: integer;
   e,t: real;
procedure REBUT(var nr: integer);
var
	r: real;
   i: integer;
begin
	nr:= 0;
   for i:=1 to n do
   	begin
      	write('rezistenta:',i:3,' are valoarea');
         readln(r);
         if abs(r-e)/e > t then
         	nr:= nr+1;
      end;
end;
begin
	write('dati numar piese din lot:');
   readln(n);
   write('dati valorile rezistentei etalon si tolerantei:');
   readln(e,t);
   writeln('dati valorile resistentelor din lot 1');
   REBUT(nr1);
   writeln('dati valorile rezistentelor din lot 2');
   REBUT(nr2);
   writeln;
   if nr1 < 2 then
   	writeln('procedeul 1 este mai bun')
   else
   	if  nr2 < 1 then
      	writeln('procedeul 2 este mai bun')
      else
      	writeln('procedeele sunt egale');
   readln;
end.

