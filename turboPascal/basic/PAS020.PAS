program test;
uses CRT;
var
	an: integer;
begin
	write('In ce an s-a nascut Eminescu?');
   readln(an);
   case an of
   	1850: writeln('Foarte bine');
      1849,1851: writeln('Aproape bine');
      1845..1848: writeln('Cu ', 1850-an,' ani mai tirziu');
      1852..1855: writeln('Cu ', an-1850,' ani mai devreme');
      1800..1844,1856..1899: writeln('Ati nimerit secolul');
      else writeln('Cultura dumneavoastra are lacune grave');
   end
end.