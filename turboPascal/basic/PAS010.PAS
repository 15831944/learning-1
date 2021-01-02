program test_ascii;
var
	c: char;
   cod: integer;
begin
	write('Caracter:');
   readln(c);
   write('Cod ASCII:');
	readln(cod);
   writeln(ord(c) = cod,'! Caracterul ', c,' are codul ',ord(c));
end.