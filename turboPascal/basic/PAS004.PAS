program operatii_aritmetice;
begin
{ operatii artimetice "fara probleme" }
	writeln('2 + 3 =', 2+3);
   writeln('2 - 3 =', 2-3);
   writeln('2 * 3 =', 2*3);
   writeln('2 / 3 =', 2/3);
   writeln('2 / 3 =', 2/3: 5: 2);
	writeln('2 mod 3 =', 2 mod 3);
	writeln('6000. * 6000 / 6000 =', 6000.*6000/6000);
	writeln;
	writeln('32767 + 2 =', 32767 + 2);
	writeln('-20 - 32767 =', -20 -32767);
	writeln('6000 * 6000 / 6000 =', 6000*6000/6000);
   writeln('1E-20 * 1E-20 =',1E-20 * 1E-20);
   writeln('2147483647. * 2147483647 / 2147483647 =',
		 2147483647. * 214783647/2147483647);
   writeln('1 shl 2 =', 1 shl 2);
   writeln('8 shr 2 =', 8 shr 2);
	writeln;
{ operatii aritmetice "cu probleme" }
	writeln('2147483647 + 5 =',2147483647 + 5);
   writeln('-2147483647 - 20 =', -2147483647 - 20);
   writeln('2147483647 * 2147483647 / 2147483647 =',
   	2147483647 * 2147483647 / 2147483647);
   writelen('3.4E-4932 * 3.4E-4932 ='. 3.4E-4932*3.4E-4932);
end.
