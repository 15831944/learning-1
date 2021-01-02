program ADMITERE;
{$R+}
const
	max_candidati = 10;
   max_probe = 10;
   max_puncte = 20;
type
	indice_candidati = 1..max_probe;
   indice_probe = 1..max_probe;
   puncte = 0.. max_puncte;
   rezultate = array[indice_candidati,indice_probe] of puncte;
   medii = array[indice_candidati] of real;
var
	nc, np, na, suma, cel_mai_bun: integer;
   ic, ia: indice_candidati;
   ip: indice_probe;
   rez: rezultate;
   m: medii;
begin
	{ citeste numar candidati, numar probe si numar admisi }
   repeat
   	write('Numar candidati [1..',max_candidati,']: ');
      readln(nc);
   until nc in [1..max_candidati];
   repeat
   	write('Numar proble [1..',max_probe,']: ');
      readln(np);
   until np in [1..max_probe];
   repeat
   	write('Citi candidati sunt admisi? ');
      readln(na);
   until na in [1..nc];
   { citeste rezultate obtinute de candidatii, calculind pe parcus media fiecarui candidat }
   writeln('Introduceti numarul de puncte obtinut de cei ',
		nc,' candidati de cele ',np,' probe');
   write('Probe: ');
   for ip:=1 to np do
   	write(ip:3);
   writeln;
   write('--------------');
   for ip:=1 to np do
   	write('---');
   writeln;
   for ic:= 1 to nc do
   begin
   	write('Candidatul',ic:3,':');
      suma:=0;
      for ip:=1 to np do
      begin
      	read(rez[ic,ip]);
         suma:= suma + rez[ic,ip];
      end;
      m[ic]:=suma/np;
	end;
   writeln;
   { alege candidatii admisi }
   writeln('Sunt declarati admisi urmatii ', na, ' candidati:');
   for ia:=1 to na do
   begin
   	{ localizeaza candidatul cu punctaj maxim }
      cel_mai_bun:=1;
      for ic:=2 to nc do
      	if m[ic] > m[cel_mai_bun] then
         	cel_mai_bun:=ic;
         { afiseaza informatiile despre candidatul cu cel mai bun punctaj
          si elimina candidatul dintre cei ce trebuie selectionati }
          writeln(cel_mai_bun:5,' cu media ',m[cel_mai_bun]:4:2);
          m[cel_mai_bun]:= -m[cel_mai_bun];
   end;
   { reface valorile mediilor }
   for ic:=1 to nc do
   	m[ic]:= abs(m[ic])
end.