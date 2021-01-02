program fwd1;
var
	x: integer;
function sus(var i: integer): integer;
	forward;
function jos(var i: integer): integer;
begin
	i:= i div 2;
   writeln(i);
   if i <> 1 then i:= sus(i);
end;
function sus;
begin
	while i mod 2 <> 0 do
   begin
   	i:=i*3 + 1;
      writeln(i);
   end;
	i:= jos(i)
end;
begin
	write('dati un numar intreg: ');
   readln(x);
   x:= sus(x);
   writeln('Sfirsitul programului');
   readln;
end.