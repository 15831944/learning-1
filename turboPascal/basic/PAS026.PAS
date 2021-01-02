program suma_1;
var
	n,i,val,s: integer;
begin
	repeat
   	write('Numar valori = ');
      readln(n)
	until n > 0;
   s := 0;
   for i := 1 to n do
   begin
   	repeat
      	write('Valoarea ',i,' : ');
         readln(val);
      until val > 0;
      s := s+ val;
   end;
   writeln('Suma celor ', n,' valori este ',s);
end.