program fwd2;
var
	x: integer;
begin
	write('dati un intreg: ');
   readln(x);
   while x <> 1 do
   begin
   	if x mod 2 = 0 then
      	x:= x div 2
      else
      	x:= x*3 + 1;
      writeln(x);
   end;
   writeln('sfirsitul programului');
   readln;
end.