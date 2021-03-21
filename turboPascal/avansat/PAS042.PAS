program DIV_MELODII;
uses CRT;
const
	max_melodie = 20;
type
	tip_nume = string[20];
   indice_melodie = 1..max_melodie;
   interpret = (formatie, solist);
   melodie = record
				titlu, autor, interpret: tip_nume;
				numar_puncte: integer;
				loc: indice_melodie;
				case interpretare: interpret of
					formatie: (numar: integer; sef:tip_nume);
					solist: (orchestra: tip_nume);
				end;
   fisier_melodii = file of melodie;
var
	melodia: melodie;
   numefis: tip_nume;
   fismel: fisier_melodii;
{ cauta intr-un fisier melodiile unui anumit  compozitor si afiseaz poz acestora }
procedure LISTA(var f: fisier_melodii; x: tip_nume; var exista boolean);
var
	m: melodie;
begin
	reset(f);
   exista := false;
   while not eof(f) do
   begin
   	read(f,m);
      if m.autor = x then
      begin
      	writeln(filepos(f)-1);
         exista := true
      end
   end;
   close(f);
end;

{concatenarea a doua fisiere cu componente de acleasi tip}
procedure CONCATF(n1,n2: nume);
var
	f1,f2: fisier;
   c: componenta;
begin
	assign(f1,n1);
   reset(f1);
   assign(f2,n2);
   reset(f2);
   seek(f1, filesize(f1));
   while not eof(f2) do
   begin
   	read(F2,c);
      write(f1,c)
   end;
   close(f1);
   close(f2);
end;

procedure COPIAZA_MELODII;
var
	c: melodie;
   fisS,fisD: fisier_melodii;
   x: char;
   numeS, numeD: tip_nume;
begin
	write('Nume fisier sursa = ');
   readln(numeS);
   asssign(fisS,numeS);
   reset(fisS);
   write('Nume fisier destinatie = ');
   readln(numeD);
   assign(fisD, numeD);
   rewrite(fisD);
   writeln('Introduceti litera D pentru melodiile copiate');
   while not eof(fisS) do
   begin
   	read(fisS,c);
      write(c.titlu,' (',c.interpret,') : ');
      x:=readkey;
      if upcase(x) = 'D' then
      	begin
         	c.nume_puncte := 0;
            write(fisD, c);
            writeln('D');
         end
      else
      	writeln
   end;
   close(fisS);
   close(fisD)
end;

procedure ELIMINA_MELODII;
var
	c: melodie;
   fisS, fisD: fisier_melodii;
   x: char;
   numeS: tip_nume;
begin
	write('Nume fisier sursa = ');
   readln(numeS);
   assign(fisS, numeS);
   reset(fisS);
   assign(fisD,'temporar.tmp');
   rewrite(fisD);
   writeln('Introduceti itera D pentru melodiile eliminate ');
   while not eof(fisS) do
   begin
   	read(fisS, c);
      write(c.titlu,' (', c.interpret,') :');
      x := readkey;
      if upcase(x) <> 'D' then
      	begin
         	c.numar_puncte := 0;
            write(fisD, c);
            writeln
         end
      else
      	writeln('D')
   end;
   close(fisS);
   close(fisD);
   erase(fisS);
   rename (fisD, numeS)
end;

