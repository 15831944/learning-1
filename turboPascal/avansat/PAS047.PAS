program LISTA;
type
	nume = string[20];
   leg_prieten = ^prieten;
   prieten = record
   				nume_prieten: nume;
	            virsta: integer;
            	urmatorul: leg_prieten;
               lista_prieteni: leg_prieten
   			end;
var
	inceput, curent: leg_prieten;
   nume_citit: nume;
   virsta_citita: integer;

procedure actualizare1(var pozitie: leg_prieten);
begin
	new(pozitie);
   with pozitie^ do
   begin
   	nume_prieten := nume_citit;
      virsta := virsta_citita;
      urmatorul := nil
   end
end;

procedure afisare_lista;
begin
	curent := inceput;
   repeat
   	writeln(curent^.nume_prieten);
      curent := curent^.urmatorul
   until curent = nil
end;


function cauta(legatura: leg_prieten; var pozitie: leg_prieten; n: nume): boolean;
var
	gasit: boolean;
begin
	gasit:= false;
   while (legatura <> nil) and not gasit do
   begin
   	if legatura^.nume_prieten = n then
      begin
      	gasit := true;
         pozitie := legatura
      end
      else
      	if legatura^.lista_prieteni <> nil then
         	gasit := cauta(legatura^.lista_prieteni, pozitie, n);
         if not gasit then
           	legatura := legatura^.urmatorul
   end;
   cauta := gasit
end;

function cauta1(var legatura: leg_prieten; n: nume): boolean;
begin
	while (n<>legatura^.nume_prieten) and (legatura^.urmatorul <> nil) do
   	legatura := legatura^.urmatorul;
   cauta1 := legatura^.nume_prieten = n
end;


function citire_lista1: boolean;
begin
	write('nume prieten = ');
   readln(nume_citit);
   curent := inceput;
   if not cauta1(curent, nume_citit) then
   	begin
      	write('ce virsta are ? ');
         readln(virsta_citita);
         actualizare1(curent^.urmatorul);
         citire_lista1 := true
		end
   else
   	citire_lista1 := false
end;

procedure actualizeaza(var pozitie: leg_prieten);
begin
	new(pozitie);
   with pozitie^ do
   begin
   	nume_prieten := nume_citit;
      virsta := virsta_citita;
      lista_prieteni := nil;
      urmatorul := nil
   end
end;

function citire_lista: boolean;
var
	pozitie: leg_prieten;
begin
	write('Care este prietenul comun = ');
	readln(nume_citit);
   curent := inceput;
   if cauta(curent, pozitie, nume_citit) then
   	begin
      	write('Numele prietenului = ');
         readln(nume_citit);
         write('ce virsta are ? ');
         readln(virsta_citita);
         if pozitie^.lista_prieteni <> nil then
         begin
         	pozitie := pozitie^.lista_prieteni;
            while pozitie^.urmatorul <> nil do
            	pozitie := pozitie^.urmatorul;
				actualizeaza(pozitie^.urmatorul);
         end
         else
         	actualizeaza(pozitie^.lista_prieteni);
         citire_lista:= true
      end
   else
   	citire_lista := false
end;

procedure listare_prieteni(legatura: leg_prieten; nivel: integer);
begin
	while legatura <> nil do
   begin
   	writeln(legatura^.nume_prieten, ' este pe nivel: ', nivel);
   	if legatura ^.lista_prieteni <> nil then
   		listare_prieteni(legatura^.lista_prieteni, nivel + 1);
		legatura := legatura^.urmatorul
   end
end;