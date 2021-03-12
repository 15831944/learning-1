program parstring;
type
	str255 = string[255];
   str80 = string[80];
var
	str1: str255;
   str2: str80;
procedure blank(var s: str255);
begin
	s:= ' '
end;

begin
	blank(str1); { corect }
   blank(str2); { incorect }
end.