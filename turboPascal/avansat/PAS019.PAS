program tabelare;
var
	x,a,b: real;
function f(x:real): real;
begin
	if x <= -1 then
   	f:= x*x
   else if x <= 1 then
   	f:= x+ 3
   else
   	f:= arctan(x);
end;
begin
	write('limitele de tabelare sunt:');
   readln(a,b);
   x:= a;
   while x <= b do
   begin
   	writeln('f(',x:6:3,')',f(x):6:2);
      x:= x + 0.01;
   end;
   readln;
end.