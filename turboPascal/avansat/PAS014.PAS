program calcul4;
var
	a,b : real;
procedure tip (x,y: real);
var
	c: real;
begin
	c:=x+y;
   writeln(c);
   writeln('****************');
end;
begin
	read(a,b);
   tip(a,b);
   tip(a*b,a/b);
end.