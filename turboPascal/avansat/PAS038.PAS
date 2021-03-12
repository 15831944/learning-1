program setcar;
const
	maxlin = 60;
type
	linie = string[maxlin];
   caractere = set of char;
var
	linia_curenta: linie;
   x: char;
   i: integer;
   c: caractere;
procedure scrie(a: linie; prim, ultim: char);
var
	x: char;
begin
	writeln(a); { scrie antet }
   if [prim .. ultim] * c = [] then
   	{ in multime nu exista nici un carcter dintre cel ecautate }
      writeln(' nu exista')
   else
   	{tipareste caracterele cautate ce apartin multimii c}
      begin
      	for x:= prim to ultim do
         if x in c then
         	write(x:2);
         writeln
      end
end; {scrie}
begin {program }
{construieste multimea carcterelor din text }
	c := [];
   repeat
   	readln(linia_curenta);
      for i:= 1 to length(linia_curenta) do
      	c := c +[linia_curenta[i]];
   until linia_curenta = '';
   {tipareste primele trei grupuri de caractere}
   scrie('Litere mari:','A','Z');
   scrie('Litere mici:','a','z');
	scrie('Cifre:','0','9');
   { elimina literele mari, literele mici si cifrele din multime
	tipareste caracterele ramase }
   c := c - ['A'..'Z','a'..'z','0'..'9'];
   scrie('Alte caractere:',#33,#126)
end.