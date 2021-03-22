program NUMAR_LINII;
type
	un_nume = string[20];
var
	f: text;
   numar: integer;
   nume: un_nume;
begin
	write('Nume fisier: ');
	readln(nume);
   assign(f, nume);
	reset(f);
	numar := 0;
	while not eof(f) do
	begin
		readln(f);
		numar := numar  + 1
   end;
   close(f);
   writeln('Fisierul are ', numar, ' linii')
end.