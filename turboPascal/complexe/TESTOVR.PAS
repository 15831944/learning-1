{$O+,F+}
unit ovr1;
INTERFACE
procedure mesaj1;
IMPLEMENTATION
procedure mesaj1;
	begin
		writeln('mesaj1')
	end;
end.

{$O+,F+}
unit ovr2;
INTERFACE
procedure mesaj2;
IMPLEMENTATION
procedure mesaj2;
	begin
   	writeln('mesaj2')
   end;
end.



{$O+,F+}
program testovr;
uses overlay, ovr1,ovr2;
{$O ovr1}
{$O ovr2}

begin
	ovrinit('testovr.ovr'}
	{ initializare plasata inaintea primului aple al unei proceduri suprapuse}
   mesaj1;
   mesa2;
   readln
end.