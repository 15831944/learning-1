program echivalente;
const
	r= 200;
   n= 20;
type
	mult = set of 1..n;
var
   clase: array[1..n] of mult;
   i,j,nr,a,b: 1..r;
   sem: boolean;
begin
	{initializarea claselor}
   for i := 1 to n do
   	clase[i] := [];
   write('dati numarul de perechi:');
   readln(nr);
   writeln('dati perechile de valori');
   for i:= 1 to nr do
   begin
   	write('perechea',i:2,' este:');
      readln(a,b);
      clase[a] := clase[a] + [a,b];
      clase[b] := clase[b] + [a,b];
   end;
   { comasarea claselor }
	for i := n downto 1 do
   begin
   	sem := false;
      for j := i-1 downto 1 do
	      if i in clase[j] then
   	   begin
      		clase[j] := clase[j] + clase[i];
         	sem := true
	      end;
      if sem then
      	clase[i] := []
   end;
	for i:= 1 to n do
   	if clase[i] <> [] then
      begin
      	write('clasa',i:3,' are elementele:',i:3);
         for j := i + 1 to n do
         	if j in clase[i] then
            	write(',',j:3);
         writeln
      end;
   readln
end.