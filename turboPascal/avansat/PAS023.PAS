program comparare;
var
	i1,i2: integer;
   r1,r2: real;
function compara(var x,y; fel: char): integer;
var
	areal: real Absolute x;
   breal: real Absolute y;
   ainteger: integer Absolute x;
   binteger: integer Absolute y;
begin
	case fel of
   	'R': {real}
      	if areal > breal then compara:= 1
         else if areal<breal then compara:= -1
         else compara:= 0;
      'I': {intreg}
      	if ainteger>binteger then compara:= 1
         else if ainteger < binteger then compara:=-1
         else compara:= 0;
   end;
end;

begin
	r1:= 10000.0;
   r2:= -33.0;
   writeln(compara(r1,r2,'R'));
   i1:= 100;
   i2:= 100;
   writeln(compara(i1,i2,'I'));
end.