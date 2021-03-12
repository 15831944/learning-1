program integrala;
type tfunc = function(x:real): real;
var x1,x2, dx:real;

function f1 (x: real) : real;
begin
	f1 := sqr(x)*sin(x)
end;

function f2 (x:real): real;
begin
	f2 := arctan(x) + ln(x)
end;

function integ (ls,ld, pas: real; f: tfunc): real;
var x,s:real;
begin
	x := ls;
   s := 0;
   while x < ld do
   begin
   	s := s + f(x);
      x := x + pas
   end;
   integ := s *pas
end;
begin
	writeln('valoarea sumei integralelor este:', integ(1,2,0.01,f1)
		+ integ(1,2,0.01,f2));
   readln
end.