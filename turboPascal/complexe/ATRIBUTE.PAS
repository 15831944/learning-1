program atribute;
uses DOS;
var
	fisier: FILE;
   nume: string;
   atribut: word;
begin
	write('Nume fisier studiat: ');
   readln(nume);
   assign(fisier, nume);
   GetFAttr(fisier, atribut);
   writeln(' fisierul ', nume);
   if (atribut and ReadOnly) = ReadOnly then
   	writeln(' este protejat la scriere ');
   if (atribut and Hidden) = Hidden then
   	writeln(' este invizibil');
   if (atribut and VolumeID) = VolumeID then
   	writeln(' este eticheta de volum ');
   if (atribut and Directory) = Directory then
   	writeln(' este sub director');
   if (atribut and Archive) = Archive then
   	writeln(' nu este arhivat cu BACKUP');
   writeln
end.