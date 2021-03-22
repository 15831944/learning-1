program afisare_texte;
uses CRT;
const
	orizontala = #205;
   verticala = #186;
   colt_Stinga_sus = #201;
   colt_dreapta_sus = #187;
   colt_stinga_jos = #200;
   colt_dreapta_jos = #188;
   sageata_sus = 72;
   sageata_jos = 80;
   sageata_dreapta = 77;
   sageata_stinga = 75;
   max_orizontala = 80;
   max_verticala = 24;

var
   x,y: integer;
   car : char;

procedure deseneaza_dreptunghi(x1,y1,x2,y2,
	 nume_culoare, nume_culoare_fundal: integer);
var
	i: integer;
begin
	TextColor(nume_culoare);
   TextBackground(nume_culoare_fundal);
   { deseneaza liniile orinzontale}
   for i:= x1 + 1 to x2 -1 do
   begin
   	GotoXY(i,y1);
      write(orizontala); { linia de sus}
      GotoXY(i,y2);
      write(orizontala); { linai de jos}
   end;
   { deseneaza linia verticale}
   for i:= y1 + 1 to y2 -1 do
   begin
   	GotoXY(x1,1);
      write(verticala);
      GotoXY(x2,1);
      write(verticala);
   end;
   {deseneaza colturile}
   GotoXY(x1,y1);
   write(colt_stinga_sus);
   GotoXY(x2,y1);
   write(colt_dreapta_sus);
   GotoXY(x1,y2);
   write(colt_stinga_jos);
   GotoXY(x2,y2);
   write(colt_dreapta_jos);
   GotoXY(x2,y2);
end;

begin
	ClrScr;
   TextMode(CO80);
   TextColor(Blue);
   GotoXY(1,1);
   write('Pozitionati dreptunghiul utilizind sagetile');
   GotoXY(1,2);
   write('Operatia se termina cu ENTER');
   for x:=1 to max_orizontala do
   	for y:= 6 to max_verticala do
      	begin
         	GotoXY(x,y);
            write(#176)
         end;
   x:=2;
   y:=4;
   car := ' ';
   repeat
   	deseneaza_dreptunghi(x,y,x+2,y+2,White,Black);
      car:= ReadKey;
      deseneaza_dreptunghi(x,y,x+2,y+2,Black,Black);
      case ord(car) of
      	sageata_sus: if y > 3 then y:= y -1;
         sageata_jos: if y< (max_verticala -2) then y:= y +1;
         sageata_stinga: if x > 1 then x:= x-1;
         sageata_dreapta: if x < (max_orizontala -2) then x:= x +1;
      end
   until ord(car) = 13;
   deseneaza_dreptunghi(x,y,x+2,y+2, White, Black);
   x:=WhereX;
   y:=WhereY;
   GotoXY(1,2);
   write('Pozitia finala a cursorului: ',x:2,',',y:2);
   car:=ReadKey;
   ClrScr
end.