program NUMARA_MELODII;
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
	nf, ns : integer;
   numefis: tip_nume;
   fismel: fisier_melodii;
begin
	writeln;
   writeln('ACEST PROGRAM ANALIZEAZA UN FISIER DE MELODII');
   writeln;
   write(' Nume fisier = ');
   readln(numefis);
   assign(fismel, numefis);
   reset(fismel);
   ns := 0;
   nf := 0;
   while not eof(fismel) do
   begin
   	read(fismel, melodia);
      case melodia.interpretare of
      	formatie: nf := nf + 1;
         solist: ns := ns + 1
      end
   end;
   close(fismel);
   if nf + ns = 0 then
   	writeln(' Fisier vid !')
   else
   	begin
      	writeln('Fisierul contine informatii despre ', nf + ns, ' melodii, dintre care:');
         writeln(nf,' interpretate de formatii si ', ns,' intrepretate de solisti')
      end
end.