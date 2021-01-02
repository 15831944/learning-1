program testproc;
const
	nmax = 100;
type
	lot = array[1..nmax] of real;
var
	n,i,nr1,nr2: integer;
   e,t: real;
	r1,r2: lot;
procedure REBUT(r: lot; var nr: integer);
begin
	nr:= 0;
   for i:= 1 to n do
   	if abs(r[i]-e)/e > t then
      	nr:= nr + 1;
end;
procedure CITIRELOT(NRLOT: integer; var R: lot);
begin
	writeln('dati valorile rezistentelor din lot ', NRLOT);
   for i:= 1 to n do
   	begin
			write('rezistenta',i:3,' are valoare');
         readln(R[i]);
      end;
end;

begin
	write('dati numar piese din lot:');
   readln(n);
   write('dati valorile rezistentei etalon si toleranta');
   readln(e,t);
   CITIRELOT(1,r1);
   CITIRELOT(2,r2);
   writeln;
   REBUT(r1,nr1);
   REBUT(r2,nr2);
   if nr1 < 2 then
   	writeln('precedeul 1 este mai bun')
   else
   	writeln('procedeele sunt egale');
   readln;
end.