program utilizare_while;
uses CRT;
var
	punctaj_candidat, punctaj_angajare: integer;
   numar_de_ordine: integer;
   numar_candidat_ales: integer;
begin
	{citeste punctajul primului candidat }
   clrscr;
   write('Ce ppunctaj aati obtinut? ');
   readln(punctaj_candidat);
   punctaj_angajare:=punctaj_candidat;
   numar_de_ordine := 1;
   numar_candidat_ales:= numar_de_ordine;
   while punctaj_candidat > 0 do
   {compara cu punctajele urmatoare}
   begin
   	numar_de_ordine:= numar_de_ordine +1;
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
   if punctaj_angajare > 0
	   then
      	begin
      	writeln('Dintre cei ', numar_de_ordine -1, ' candidati prezentati');
   		writeln('Optam pentru candidatul ',numar_candidat_ales, ' care a obtinut ',
				punctaj_angajare,' puncte');
         end
      else
      	writeln('!!! Nu au existat candidati!!');
end.