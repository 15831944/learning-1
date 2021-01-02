program celmai;
var
	a,b: integer;

function cmmdc(m,n: integer): integer;
begin
	if n= 0 then
   	cmmdc:= m
   else
   	cmmdc:= cmmdc(n,m mod n)
end;

begin
	writeln('dati doua numere intregi pozitive:');
   readln(a,b);
   writeln('cel mai mare divizor comun este: ',cmmdc(a,b));
   readln;
end.