program invers;
procedure invsir;
var
	c: char;
begin
	read(c);
   if c <> ' ' then invsir;
   write(c);
end;

begin
	writeln('dati o seccesiune de caractere terminata cu blanc:');
   invsir;
   readln;
   readln;
end.