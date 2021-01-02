program sizeofData;
var
	b: byte;
   f: ShortInt;
   i: Integer;
   l: Longint;
   w: Word;
   r: real;
   s: single;
   d: double;
   e: extended;
   c: comp;
begin
	writeln('SizeOf(b) =',SizeOf(b));
   writeln('SizeOf(f) =',SizeOf(f));
   writeln('SizeOf(l) =',SizeOf(l));
   writeln('SizeOf(w) =',SizeOf(w));
   writeln('SizeOf(r) =',SizeOf(r));
   writeln('SizeOf(s) =',SizeOf(s));
   writeln('SizeOf(d) =',SizeOf(d));
   writeln('SizeOf(e) =',SizeOf(e));
   writeln('SizeOf(c) =',SizeOf(c));
end.