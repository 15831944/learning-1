program utilizare_repeat_1;
uses CRT;
var
	punctaj_candidat, punctaj_angajare: integer;
   numar_de_ordine: integer;
   numar_candidat_ales: integer;
begin
   punctaj_angajare:= -1;
   numar_de_ordine:=1;
   repeat
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
      numar_de_ordine:=numar_de_ordine + 1;
until punctaj_candidat <= 0;
   clrscr;
   if punctaj_angajare > 0
	   then
      	begin
      	writeln('Dintre cei ', numar_de_ordine -2, ' candidati prezentati');
   		writeln('Optam pentru candidatul ',numar_candidat_ales, ' care a obtinut ',
				punctaj_angajare,' puncte');
         end
      else
      	writeln('!!! Nu au existat candidati!!');
end.