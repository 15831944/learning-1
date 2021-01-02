program vinzare_cumparare;
const
	pret_unitar = 10.5;
var
	cantitate: integer;
begin
	write('Ce cantitate doriti ?');
	readln(cantitate);
   writeln('Suma de plata =',cantitate * pret_unitar: 4: 2);
end.