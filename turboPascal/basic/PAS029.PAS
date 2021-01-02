program suma_2;
const
	MAX = 10;
var
	n,val,s: integer;
begin
	s := 0;
   n := 0;
   repeat
   	write('Valoarea ', n+1,':');
      readln(val);
      if  val > 0
	      then
         	if s > maxint -val
	            then
               	begin
			         	writeln('Suma primelor ',n,' valori este ',s);
         			   writeln('Daca se adauga si urmatoarea (',val,') se produce depasirea');
                     halt; { oprire fortata}
			         end
               else
               	begin
                  	n:=n+1;
                     s:=s+val;
                  end
   until (val < 0) or (n = MAX);
  	if n = 0
     	then
        	writeln('Date inexistente')
      else
        	writeln('Suma celor ',n, ' valori este ',s);
end.