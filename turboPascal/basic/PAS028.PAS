program suma_3;
const
	MAX = 5;
label
	Gata,Depasire,Sfirsit;
var
	n,val,s: integer;
begin
	s := 0;
   for n:= 1 to MAX do
   begin
   	write('Valoarea ',n,' : ');
      readln(val);
      if val <= 0 then
      	begin
         	n:= n-1;
            goto Gata
         end;
      if s > maxint -val then
      	goto Depasire;
		s := s + val;
   end;
   Gata:
   	if n = 0 then
      	writeln('Date inexistente!')
      else
      	writeln('Suma celor ', n,' valori este ',s);
      goto Sfirsit;
   Depasire:
   	writeln('Suma primelor ', n -1, ' valori este ',s);
      writeln('Daca se aduaga si valoarea urmatoare (',val,') se produce depasire');
   Sfirsit:
   	readln
end.