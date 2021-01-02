program calcule;
var
	i,j: integer;
   x: real;
begin
	write('Introduceti o valoare de tip real :');
   readln(x);
   i:= trunc(x);
   j:= round(x);
   { afisare rezultate }
   writeln('Rezultatele programului sunt:');
   writeln;
   writeln('x = ',x:6:2,', trunc(x) =',i,' , round(x) =',j);
end.