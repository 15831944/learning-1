program angajare;
uses CRT;
var
	virsta: integer;
   media: real;
begin
	write('Introduceti virsta si media obtinute la bacalaureat:');
   readln(virsta, media);
   clrscr;
   if (virsta < 20) or (virsta > 30) or (media < 9)
      then
   	    writeln('Ne pare rau, nu indepliniti conditiile de angajare')
      else
   	    writeln('Va invitam sa participati la testul de angajare');
end.