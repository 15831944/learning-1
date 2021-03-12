program stringtest;
procedure ScrieMajuscule(st: string);
{ transforma toate caracterele sirulu st in
majuscule si-i afiseaza; sirul st are lungimea
implicita 255}
var
	i: integer;
begin
	for i:= 1 to length(st) do
   	st[i] := UpCase(st[i]);
      writeln(st)
end;

begin
	ScrieMajuscule(' Acesta este un sir constant')
end.