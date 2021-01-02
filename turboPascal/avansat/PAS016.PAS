program testparam;
var
	a,b : integer;
procedure schimba (var x,y: integer);
var
	temp: integer;
begin
	temp := x;
   x := y;
   y := temp;
end;
begin
	a:= 1;
   b:= 2;
   schimba(a,b);
   writeln(a:2,b:2);
   readln;
end.