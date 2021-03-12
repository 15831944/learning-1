program CARACTERE;
const
	maxlin = 60;
type
	linie = string[maxlin];
   caractere_imprimabile = #32 .. #126;
   evidenta = array[caractere_imprimabile] of boolean;

var
	l: linie;
   x: char;
   i: integer;
   gasit: evidenta;

procedure SCRIE(a: linie; prim, ultim: char);
var
	x: char;
   exista: boolean;
begin
	writeln(a); { scrie antet}
   exista := false;
   {scrie caractere gasite}
   for x:= prim to ultim do
   	if gasit[x] then
      begin
      	write(x:2);
         exista := true
      end;
   { finalizare scriere }
   if exista then
   	writeln
   else
   	writeln(' nu exista')
end;

begin {program}
	{ initializeaza vectorul gasit }
   for x:=#32 to #126 do
   	gasit[x] := false;
   { prelucreaza linii }
   repeat
   	readln(l);
      for i:= 1 to length(l) do
      { marcheaza gasirea caracterului l[i] }
      	gasit[l[i]] := true;
   until l = '';
   { tipareste caracterele din primele trei grupuri }
   SCRIE('Litere mari:','A','Z');
   SCRIE('Litere mici:','a','z');
   SCRIE('Cifre:','0','9');
   { elimina caracterele apartinind primele trei grupuri }
   for x:='A' to 'Z' do
   	gasit[x] := false;
   for x:='a' to 'z' do
   	gasit[x] := false;
   for x:='0' to '9' do
   	gasit[x] := false;
   { tipareste caracterele din al patrulea grup }
   SCRIE('Alte caractere:', #32, #126)
end.