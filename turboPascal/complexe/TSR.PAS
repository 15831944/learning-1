{$M 20000,0,0}
{$R-,S-,I-,D+,F+,V-,B-,N-,L+}
program tsr;
uses Crt, Dos;

const
	nivel_tastatura = 0;
   nivel_disc_BIOS = $13;
   nivel_Dos = $28;
   port_scan_cod = $60;
   port_tastatura = $61;
   port_EOI = $20;
   EOI = $20;
   tasta_executie = 67;
   tasta_sfirsit = 68;
type
	adr_ecran = ^tip_ecran;
   tip_ecran = record
   			pozitie: array[1..25,1..80] of
            	record caracter: char;
               		atribut: char;
               end;
            end;

var
	registre: Registers;
   pozitie_cursor_x, pozitie_cursor_y: byte;
	executie_TSR_in_curs, in_BIOS, cerere: boolean;
   salvere_ecran, memorie_ecran: adr_ecran;
	ecran: tip_ecran;
   in_DOS: Pointer;
   in_dos_ofs: word;
   in_dos_seg: word;
   tratare_nivel_9: Pointer;
   tratare_nivel_13: Pointer;
   tratare_nivel_28: Pointer;
   salvare_stiva_curenta: Pointer;
   adresa_stiva_ofs, adresa_stiva_seg: word;
   stiva_noua: array[1..200] of word;
   stiva_DOS: array[1..128] of word;
   tasta: byte;
   tasta_salvata: byte;

procedure dezactivare_intreruperi;
   InLine($FA);

procedure activare_intreruperi;
   InLine($FB);

procedure apel_tratare_veche(procedura_veche: Pointer);
begin
	asm
   	pushf
      call dword ptr procedura_veche
   end
end;

procedure terminare;
begin
	{refacere nivele de intrerupere afectate }
   dezactivare_intreruperi;
   SetIntVec(nivel_tastatura, tratare_nivel_9);
   SetIntVec(nivel_disc_BIOS, tratare_nivel_13);
   SetIntVec(nivel_DOS, tratare_nivel_28);
   activare_intreruperi;
end;

procedure executie_TSR;
begin
	executie_TSR_in_curs := true;
   {salvare adresa stiva curenta}
   adresa_stiva_seg := SSeg;
   adresa_stiva_ofs := SPtr;
   salvare_stiva_curenta := ptr(adresa_Stiva_seg, adresa_stiva_ofs);
   { pozitionare stiva curenta }
   asm
   	push ax
      mov ax,seg stiva_noua
      mov ss, ax
      pop ax
      mov sp, offset stiva_noua + 199*2
   end;

   {salvare 128 de cuvinte din stiva DOS}
   move(salvare_Stiva_curenta^,stiva_DOS, 128*SizeOf(word));
   if tasta_salvata = tasta_sfirsit then
   	terminare
   else
   	begin
      	{determina mod eafisare}
         registre.ah := 15;
         intr($10,registre);
         if registre.al = 3 { daca modul 25x80} then
         begin
         	{salvare continut ecran}
            memorie_ecran := ptr($B800 + registre.bh * $2000, 0);
            ecran := memorie_ecran^;
            {determina pozitie cursor}
            pozitie_cursor_x := WhereX;
            pozitie_cursor_y := WhereY;
            ClrScr;
            registre.ah := $30;
            MsDos(registre);
            GoToXY(5,10);
            with registre do
            	writeln('Versiune MsDos ', al: 1,'.',ah: 2);
            {citire caracter}
            registre.ah := 0;
				intr($16,registre);
            {refacere ecran}
            memorie_ecran^:=ecran;
            {repozitionare cursor}
            GotoXY(pozitie_cursor_x,pozitie_cursor_y);
         end
      end;
   {refacere stiva DOS}
   dezactivare_intreruperi;
   	move(stiva_DOS,salvare_stiva_curenta^,128*SizeOf(word));
   {cumutare stiva}
   asm
   	mov ss,adresa_stiva_seg
      mov sp,adresa_stiva_ofs
   end;
   executie_TSR_in_curs := false;
end;

procedure int_13; interrupt;
begin
	in_BIOS := true;
   asm
   	mov ax,[bp+16]
      mov bx,[bp+14]
      mov cx,[bp+12]
      mov dx,[bp+10]
   end;
   apel_tratare_veche(tratare_nivel_13);
   in_BIOS := false;
end;

procedure int_28; interrupt;
begin
	apel_tratare_veche(tratare_nivel_28);
   dezactivare_intreruperi;
   if cerere then
   begin
   	cerere := false;
      executie_TSR;
   end;
   activare_intreruperi
end;

procedure int_9; interrupt;
var
	temp: byte;
   adresa_in_buffer: word;
begin
	tasta := port[port_scan_cod];
	if (tasta = tasta_executie) or (tasta = tasta_sfirsit) then
   begin
   	tasta_salvata := tasta;
      dezactivare_intreruperi;
      temp:=port[port_tastatura];
      port[port_tastatura] := temp or $80;
      port[port_tastatura] := temp;
      port[port_EOI] := EOI;
      if not executie_TSR_in_curs then
      	if in_BIOS or (mem[Seg(in_DOS^):Ofs(in_DOS^)] <> 0) then
         	cerere := true
         else
         	executie_TSR
   end
   else
   	apel_tratare_veche(tratare_nivel_9);
   activare_intreruperi;
end;

begin
	executie_TSR_in_curs := false;
   in_BIOS := false;
   cerere := false;
   GetIntVec(nivel_tastatura, tratare_nivel_9);
   if Ofs(tratare_nivel_9^) = Ofs(int_9) then
   	writeln('!!! Programul este deja instlaat !!')
   else
   	begin
      	GetIntVec(nivel_disc_BIOS, tratare_nivel_13);
         GetIntVec(nivel_DOS, tratare_nivel_28);
         registre.ah := $34;
         intr($21,registre);
         in_DOS := Ptr(registre.es, registre.bx);
         SetIntVec(nivel_tastatura, @int_9);
         SetIntVec(nivel_disc_BIOS, @int_13);
         SetIntVec(nivel_DOS, @int_28);
         writeln('S-a incheiat instalea programului ');
         Keep(0);
      end
end.