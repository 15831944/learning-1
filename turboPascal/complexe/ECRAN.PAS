program ecran;
uses CRT, DOS;
var
	regs: Registers;
   i,j,k: integer;
   pagina_curenta: byte;
   car: char;
   x,y: integer;

procedure alege_ecran(numar:byte);
begin
	regs.ah := 5; {selectie functie BIOS}
   regs.al := numar;
   intr($10,regs) {apel functie BIOS}
end;

procedure pozitionare_cursor(x,y: byte);
begin
	regs.ah := 2; {selectie functie BIOS}
   regs.bh := pagina_curenta;
   regs.dh := y;
   regs.dl := x;
end;

procedure construieste_pagina(numar, pozitie_x, pozitie_y: byte);
var
	i,j: integer;
begin
	for i:= pozitie_x to pozitie_x + 2*(numar + 1) do
   	for j:= pozitie_y to pozitie_y + 4* (numar + 1) do
      	memw[$b800:
         	((i-1)*80 + (j-1)) *2 + 4096 * numar]:=$71FE
end;

begin
	TextMode(Co80);
   	for i:= 0 to 3 do
      	construieste_pagina(i, 10 -i,38-2*i);
      for j:= 1 to 5 do
      begin
      	for i:= 0 to 3 do
         	begin
	         	alege_ecran(i);
   	         Delay(80)
            end;
   	   for i:= 3 downto 0 do
      	begin
      		alege_ecran(i);
	         Delay(80)
   	   end;
      end;
end.