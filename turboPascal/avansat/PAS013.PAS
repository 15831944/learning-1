program calcul3;
var
	a,b: real;
procedure tip;
	var
		c: real;
   begin
   	c:= a+b;
      writeln(c);
      writeln('****************');
   end;
begin
	read(a,b);
   tip;
end.