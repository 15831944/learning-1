program selectie_1;
uses CRT;
var
   punctaj_candidat, punctaj_angajare: integer;
   numar_candidat: integer;
begin
{ citeste punctajul primului candidat, care este
acceptat ca punctaj de angajare}
	clrscr;
   write('Ce punctaj ati obtinut? ');
   readln(punctaj_angajare);
   numar_candidat:=1;
   { citeste si prelucreaza punctajul celui de-al
   doilea candidat}
   write('Ce punctaj ati obtinut? ');
   readln(punctaj_candidat);
   if punctaj_candidat > punctaj_angajare
   	then
      	begin
         	numar_candidat:=2;
            punctaj_angajare:=punctaj_candidat;
         end;
   { citeste si prelucreaza puctajul celui de-al treilea candidat}
   write('Ce punctaj ati obtinut? ');
   readln(punctaj_candidat);
   if punctaj_candidat > punctaj_angajare
   	then
      	begin
         	numar_candidat:=3;
            punctaj_angajare:= punctaj_candidat;
         end;
   clrscr;
   writeln('Optam pentru candidatul ', numar_candidat,
   	' care a obtinut ',punctaj_angajare,' puncte');
end.