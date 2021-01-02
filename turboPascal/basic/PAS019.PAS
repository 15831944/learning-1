program test;
uses CRT;
var
	an: integer;
begin
	write('In ce an s-a nascut Eminescu? ');
   readln(an);
   if an = 1850
   	then
      	writeln('Foarte bine');
   if (an = 1849) or (an = 1851)
   	then
      	writeln('Aproape bine');
   if (an >= 1845) and (an <= 1848)
   	then
      	writeln('Cu ', 1850-an, ' ani mai tirziu');
   if (an >= 1852) and (an <=1855)
   	then
      	writeln('Cu ', an-1850,' ani mai devreme');
   if (an >=1800) and (an <= 1844) or (an>=1856) and (an <= 1899)
   	then
      	writeln('Ati nimerit secolul');
   if (an < 1800) or (an > 1899)
   	then
      	writeln('Cultura dumneavoastra are lacure grave');
end.