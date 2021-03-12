program compactare;
type
	sir = string[10];

procedure SCRIE_COMPACT(r: real);
var
	i: integer;
   s: string[18];
begin
	str(r,s);
   { elimina zerourile nesemnificative de la partea subunitara}
   i := length(s) -4;
   while s[i] = '0' do
   	i := i -1;
      delete (s,i+1,length(s)-i-4);
      { elimina punctul daca este cazul }
      if s[i] = '.' then
      	delete(s,i,1);
         { prelucreaza exponentul }
      if (s[length(s)-1] = '0') and (s[length(s)] = '0')
      	then
         	delete (s,length(s)-3,4)
         else
         	if s[length(s)-1] = '0' then
            	delete(s, length(s)-1,1);
            {afiseaza rezultatul prelucrarii }
   writeln(s)
end;
function COMPLET(numar: integer): sir;
var
	reprezentare: sir;
   j: integer;
begin
	str(abs(numar), reprezentare);
   for j:=1 to 5 - length(reprezentare) do
   	reprezentare := '0' + reprezentare;
   if numar < 0 then
   	COMPLET := '-' + reprezentare
   else
   	COMPLET := reprezentare
end;

begin
	SCRIE_COMPACT(30.67);
   writeln(COMPLET(156))
end.