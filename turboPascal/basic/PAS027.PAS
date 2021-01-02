program suma_2;
const
	MAX = 10;
var
	n,val,s: integer;
   depasire: boolean;
begin
	s := 0;
   n := 0;
   depasire := false;
   repeat
   	write('Valoarea ', n+1,':');
      readln(val);
      if  val > 0
	      then
         	if s > maxint -val
	            then
               	depasire := true
               else
               	begin
                  	n:=n+1;
                     s:=s+val;
                  end
   until (val < 0) or (n = MAX) or depasire;
   if depasire
   	then
      	begin
         	writeln('Suma primelor ',n,' valori este ',s);
            writeln('Daca se adauga si urmatoarea (',val,') se produce depasirea')
         end
      else
      	if n = 0
         	then
            	writeln('Date inexistente')
            else
            	writeln('Suma celor ',n, ' valori este ',s);
end.