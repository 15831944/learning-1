program beep;
uses crt;
var frecventa : integer;
begin
	frecventa := 100;
	sound(frecventa);
	delay(500);
	nosound;
end.