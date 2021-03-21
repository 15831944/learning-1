program ERORI_CITIRE;
type
	tip_nume = string[20];
var
	nume_sursa: tip_nume;

function FISIER_PREZENT(nume: tip_nume): boolean;
var
	x: file;
begin
	assign(x,nume);
   {$I-}
   reset(x);
   {$I+}
   if ioresult = 0 then
   	begin
      	FISIER_PREZENT := true;
         close(x);
      end
   	else

      	FISIER_PREZENT := false
end;

procedure MODIF(nume_sursa: tip_nume);
var
	fs, fr: text;
   numar_erori, valoare, numar_valori: integer;
begin
	{pregatire prelucrare}
	assign(fs, nume_Sursa);
	reset(fs);
	assign(fr,'tmp.tmp');
	rewrite(fr);
	{creare fisier temporar }
   numar_erori := 0;
   numar_valori := 0;
	{$I-}
	while not seekeof(fs) do
	begin
		read(fs, valoare);
		if ioresult <> 0
			then
				numar_erori := numar_erori + 1
			else
				begin
            	numar_valori := numar_valori + 1;
               if numar_valori mod 5 = 0 then
               	writeln(fr, valoare)
               else
               	write(fr, valoare,' ')
            end
   end;
   if numar_erori > 0 then
   	writeln('S-au detectat ', numar_erori, ' erori');
   writeln('Fisierul contine ', numar_valori,' valori intregi');
   { finalizare prelucrare }
   close(fr);
   close(fs);
   erase(fs);
   rename(fr, nume_sursa)
end;

begin
	write('Fisier = ');
   readln(nume_sursa);
   if FISIER_PREZENT (nume_sursa) then
   	MODIF(nume_sursa)
   else
   	writeln('Eroare')
end.