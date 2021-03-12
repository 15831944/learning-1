program stringuri;
type
	sir = string[10];

procedure INLOCUIRE(var s: sir; vechi, nou: sir);
var
	k,lv: integer;
begin
	lv:= length(vechi);
   k:= pos(vechi,s);
   while k > 0 do
   	begin
      	delete(s,k,lv);
         insert(nou, s, k);
         k:= pos(vechi,s)
      end
end;

var
	str1 : sir;
begin
	str1 :='abbc';
	INLOCUIRE(str1,'ab','na');
	writeln(str1);
end.
