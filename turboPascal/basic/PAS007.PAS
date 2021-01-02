program conversii_Char;
begin
{ conversii de la tipul char la tipuri numerice }
	writeln('ord("A") =',ord('A'));
   writeln('byte("A") =',byte('A'));
   writeln('word("A") =',word('A'));
   writeln('iteger("A") =',integer('A'));
   writeln('LongInt("A") =',LongInt('A'));
   writeln;

{ conversii de la tipuri numerice la tipul char }
	writeln('char(65) =',char(65));
   writeln('char(byte(65)) =',char(byte(65)));
   writeln('char(word(65)) =',char(word(65)));
   writeln('char(LongInt(65)) =', char(LongInt(65)));
end.