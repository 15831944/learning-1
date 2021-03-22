program CONCATENARE_FISIERE_TEXT;
type
	tip_nume = string[20];
var
	frez,fsursa: text;
   nume_rez, nume_sursa: tip_nume;
   c: char;

procedure citeste_nume_sursa;
begin
	write('Sisier sursa: ');
   readln(nume_sursa);
end;
begin
{ primul fisier sursa este redenumit, devenind fiser rezultat,
la care se va adauga continutul celorlalte fisiere sursa}
	write('Fisier rezultat: ');
   readln(nume_rez);
   citeste_nume_sursa;
   assign(frez, nume_sursa);
   if nume_sursa <> nume_rez then
   	rename(frez, nume_rez);
   append(frez);
   repeat
   	citeste_nume_sursa;
      if nume_sursa <> '' then
      begin
      	{ deschide urmatorul fisier sursa pentru citire si trasnfera
         continutul sau in fisierul rezultat }
         assign(fsursa, nume_sursa);
         reset(fsursa);
         while not eof(fsursa) do
         begin
         	read(fsursa, c);
            write(frez, c)
         end;
         { inchide si sterge fisierul sursa }
         close(fsursa);
         erase(fsursa);
      end
   until nume_sursa = '';
   close(frez)
end.
