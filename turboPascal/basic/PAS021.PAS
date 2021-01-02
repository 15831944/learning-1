program utilizare_for;
uses CRT;
var
	punctaj_candidat, punctaj_angajare: integer;
   numar_candidati, numar_de_ordine: integer;
   numar_candidat_ales: integer;
begin
{ citeste numarul de candidati }
	write('Citi candidati s-au prezentat?');
   readln(numar_candidati);
{ citeste punctajul primului condidat care este angajat
daca are punctaj mai mare decit urmatorii }
	clrscr;
   write('Ce punctaj ati obtinut? ');
   readln(punctaj_angajare);
   numar_candidat_ales:=1;
   { compara cu punctajele urmatorilor }
   for numar_de_ordine:=2 to numar_candidati do
   begin
   	{ citeste punctajul candidatului curent care este angajat
      daca are punctaj mai mare decit ceilalti }
      clrscr;
      write('Ce punctaj ati obtinut? ');
		readln(punctaj_candidat);
      if punctaj_candidat > punctaj_angajare
      	then
         	begin
            	numar_candidat_ales:=numar_de_ordine;
               punctaj_angajare:=punctaj_candidat;
      		end;
   end;
   clrscr;
   writeln('Optam pentru candidatul ',numar_candidat_ales, ' care a obtinut ',
		punctaj_angajare,' puncte');
end.