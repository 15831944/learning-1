program CREARE_FISIER;
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
   numar, i: integer;
   numefis: tip_nume;
   fismel: fisier_melodii;

procedure citire_melodie(var m: melodie);
var
	car: char;
begin
	with m do
   begin
   	write('Titlu = ');
      readln(titlu);
		write('Autor = ');
      readln(autor);
      write('Interpret = ');
      readln(interpret);
      write('Formatie [D/N] = ');
      readln(car);
      if (car = 'D') or (car = 'd') then
	      begin
   	   	interpretare := formatie;
      	   write(' numar membri in formatie = ');
         	readln(numar);
	         write(' conducator formatie = ');
   	      readln(sef);
	      end
      else
      	begin
         	interpretare := solist;
            write(' orchestra care acompaniaza = ');
            readln(orchestra)
         end;
      numar_puncte := 0;
   end
end;

begin
	writeln;
   writeln('ACEST PROGRAM CREAZA UN NOU FISIER DE MOLODII');
   writeln;
   write(' Nume fiser = ');
   readln(numefis);
   repeat
   	write(' Numar melodii = ');
      readln(numar)
   until numar in [1..max_melodie];
   assign(fismel, numefis);
   rewrite(fismel);
   for i:= 1 to numar do
   begin
   	citire_melodie(melodia);
      write(fismel, melodia)
   end;
   close(fismel)
end.