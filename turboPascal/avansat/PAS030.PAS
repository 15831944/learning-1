program ORDINE;
const
	dim = 8;
type
	sir = string[dim];
var
	x,y : sir;
begin
	readln(x);
   readln(y);
   if x < y
   	then
      	writeln(x,'<',y,'|')
      else
      	if y < x
         	then
            	writeln(y,'<',x,'|')
            else
            	writeln('Egalitate')
end.