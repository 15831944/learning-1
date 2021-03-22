program COPIERE;
uses DOS, CRT;

type
	nume_fisier = string[13];
var
	sursa, destinatie: File;
   buffer: array[1..500] of Byte;
   nume_s, nume_d: nume_fisier;
   rezultat: integer;
   F: SearchRec;
   car: char;

procedure lista_fisiere(var nume: nume_fisier);
var
	vector_fisiere: array[1..200] of nume_fisier;
	ord, gasit: boolean;
   i,k,n: integer;
   aux : nume_fisier;

begin
{ contruieste lista nume fisiere }
	i:= 0;
   FindFirst('*.*',Archive, F);
   while DosError = 0 do
    with F do
    	begin
      	if Attr = Archive then
         begin
         	i := i + 1;
            vector_fisiere[i] := name
         end;
         FindNext(F)
   	end;
   n := i;
   { ordonare lista nume fisiere }
	repeat
   	ord := true;
      for k:=1 to i - 1 do
      	if vector_fisiere[k] > vector_fisiere[k + 1] then
         	begin
            	aux := vector_fisiere[k];
               vector_fisiere[k] := vector_fisiere[k+1];
               vector_fisiere[k + 1] := aux;
               ord := false
            end;
      i := i -1
   until ord;
   { selectie nume fisier}
   i := 1;
   gasit := false;
   while not gasit and (i <= n) do
   begin
   	GotoXY(1,1 + i mod 24);
      write(vector_fisiere[i], '=>');
      car := readKey; { citire caractere fara ecou}
      write(car);
      if Upcase(car) = 'D' then
      	gasit := true
      else
      	i := i + 1;
   	if not gasit and (i mod 24 = 0) then
      	ClrScr
   end;
   if gasit then
		nume := vector_fisiere[i]
   else
   	nume := ''
end;

begin
	ClrScr;
   writeln('Selectati fisierul sursa');
   lista_fisiere(nume_s);
   writeln;
   if nume_s <> '' then
		begin
      	write('Nume fisier destinatie: ');
         readln(nume_d);
         {fisierul destinatie exita ?}
         FindFirst(nume_d, Archive, F);
         if DosError = 0 then
         	begin
            	{ se distruge vechiul fisier ?}
               write('Fisiserul ',nume_d, ' exista deja, se distruge ?');
               car := readKey; { citere fara ecou }
               write(car);
               if Upcase(car) <> 'D' then
               	exit
            end;
         { deschide fisier sursa }
         assign(sursa, nume_s);
         reset(sursa,1);
         {deschide fisier destinatie}
         assign(destinatie, nume_d);
         rewrite(destinatie,1);
         {executie transfer }
         BlockRead(sursa, buffer, SizeOf(buffer), rezultat);
         while rezultat > 0 do
         begin
         	BlockWrite(destinatie, buffer, rezultat);
            BlockRead(sursa, buffer, SizeOf(buffer), rezultat)
         end;
      	close(sursa);
         close(destinatie);
      end
end.