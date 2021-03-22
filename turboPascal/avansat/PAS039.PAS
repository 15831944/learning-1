program PRELUCRARE_MELODII;
const
	max_melodie = 20;
type
   indice_melodie = 1..max_melodie;
	numar_melodii = 1..max_melodie;
   tip_nume = string[20];
   interpret = (formatie, solist);
   index = array[indice_melodie] of indice_melodie;
   melodie = 	record
					titlu, autor, interpret: tip_nume;
               numar_puncte: integer;
               loc: indice_melodie;
               case interpretare: interpret of formatie: (nuamr: integer; sef: tip_nume);
               solist: (orchestra: tip_nume);
               end;
var
	melodii: array[indice_melodie] of melodie;
   numar: numar_melodii;
   pozitie: index;
   k: integer;
   car: char;
   eroare: boolean;
   titlu_c, autor_c : tip_nume;

procedure ACTUALIZARE(titlu_c, autor_c: tip_nume; puncte: integer; var eroare: boolean);
{ actualizeaza numarul de puncte acumulat de o melodie }
var
	i: indice_melodie;
begin
	i:= 1;
   eroare := true;
   while (i <= numar) and eroare do
   	if ((titlu_c = melodii[i].titlu) and (autor_c = melodii[i].autor)) then
         eroare := false
      else
      	i := i + 1;
      if not eroare then
      	melodii[i].numar_puncte := melodii[i].numar_puncte + puncte
end;

procedure TOP(var pozitie: index);
{ stabileste top-ul melodiilor in functie de numarul de puncte }
var
	i,k: indice_melodie;
   j: numar_melodii;
   ord: boolean;
begin
	for i:=1 to numar do
   	pozitie[i] := i;
   j:= numar -1;
   repeat
   	ord := true;
      for i:=1 to j do
      	if melodii[pozitie[i]].numar_puncte < melodii[pozitie[i+1]].numar_puncte
         then
         	begin
            	k := pozitie[i];
               pozitie[i]:=pozitie[i+1];
               pozitie[i+1]:=k;
               ord:=false
            end;
      j := j -1;
   until ord;
   for i:= 1 to numar do
   	melodii[pozitie[i]].loc := i
end;

procedure AFISARE(tip_interpretare: interpret; saptamina: integer);
{ afisare topul pentru un anumit tip de interpretare }
var
	i: indice_melodie;
   j: numar_melodii;
const
	descriere:array[interpret] of string[8] = ('formatii','solisti');
begin
	case tip_interpretare of
   	formatie: writeln('Topul formatiilor in ','saptamina ',saptamina);
	   solist: writeln('Topul solistilor in ','saptamina ', saptamina)
   end;
   j := 1;
   for i:= 1 to numar do
   	with melodii[pozitie[i]] do
      	if interpretare = tip_interpretare then
         	begin
            	j := j + 1;
               writeln('Locul ', j:4, ' ',titlu, ' ', autor,' ',interpret)
            end;
   if j = 0 then
   	writeln('In top nu exista melodii interpretate de ', descriere[tip_interpretare])
end;

procedure AFISARE_TOP(saptamina: integer);
{ afiseaza topul complet sub forma tabelara }
var
	i: indice_melodie;
begin
	writeln('Topul melodiilor in saptamina ', saptamina);
   for i:= 1 to numar do
   with melodii[pozitie[i]] do
   	writeln('Locul ',i:4,' ',titlu: 21-length(titlu), autor: 21-length(autor), interpret: 21-length(interpret));
end;

procedure CITIRE;
{ citeste informatiile despre melodii }
var
	i: indice_melodie;
begin
 	repeat
   	write(' Numar melodii [1..',max_melodie,'] = ');
      readln(k);
   until k in [1..max_melodie];
   numar := k;
   for i:=1 to numar do
   	with melodii[i] do
      begin
      	write('Titlu = '); readln(titlu);
         write('Autor = '); readln(autor);
         write('Interpret = ');readln(interpret);
         write('Formatie [D/N]  '); readln(car);
         if (car = 'D') or (car = 'd') then
         	begin
            	interpretare := formatie;
               write(' numar membrii in formatie = ');
					readln(numar);
               write(' conducator formatie = ');
               readln(sef)
            end
         else
         	begin
            	interpretare := solist;
               write(' orchestra care acompaniaza = ');
               readln(orchestra)
            end;
         numar_puncte := 0
      end
end;

procedure AFISARE_INFORMATII(titlu, autor: tip_nume; var eroare: boolean);
{ afiseaza informatiile despre o melodie}
var
	i: indice_melodie;
begin
	i := 1;
   eroare := true;
   while( i<= numar) and eroare do
   	if((titlu = melodii[i].titlu) and (autor = melodii[i].autor)) then
      	eroare := false
      else
      	i := i  + 1;
      if eroare then
      	writeln(' Melodia nu apare in top !')
      else
      	with melodii[i] do
         	case interpretare of
					formatie:
            	begin
               	writeln(titlu,' este interpretata de formatia ', interpret);
                  writeln(' ( formata din ', numar,'membrii si condusa de ', sef,')')
               end;
            	solist:
            	begin
               	writeln(titlu,' este intrepretata de solistul ', interpret);
                  writeln('(acompaniat de ', orchestra, ')')
               end
   end
end;

begin { program }
	CITIRE;
   writeln;
   writeln('Actualizati punctaj (pentru oprire introduceti titlu vid');
   repeat
   	writeln;
      write('Titlul melodiei = ');
      readln(titlu_c);
      if titlu_c <> '' then
      begin
      	write('Autor = ');
         readln(autor_c);
         write('Cite puncte adaugam ? ');
         readln(k);
      	ACTUALIZARE(titlu_c, autor_c, k, eroare);
         if eroare then
         	writeln('Melodia nu apare in top !')
      end
   until titlu_c ='';

   TOP(pozitie);
   AFISARE_TOP(3);
   writeln;

	AFISARE(formatie,3);
   writeln;
   writeln('Indicati melodia despre care doriti informatii');
	writeln('(pentru oprire introduceti un titlu vid)');
   repeat
   	writeln;
      write('Titlu = ');
      readln(titlu_c);
      if titlu_c <> '' then
      begin
      	write('Autor = ');
         readln(autor_c);
         AFISARE_INFORMATII(titlu_c, autor_c, eroare)
      end
   until titlu_c = '';
end.