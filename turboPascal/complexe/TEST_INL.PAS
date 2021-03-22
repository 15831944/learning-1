program test_inLine;
var
	stiva_curenta, stiva_principala: Pointer;
   stiva_ofs, stiva_seg: word;
procedure scrie_hex(numar: word);
const
	hex: array[0..15] of char = '0123456789ABCDEF';
begin
	if numar < 16 then
		write(hex[numar])
   else
   	begin
      	scrie_hex(numar div 16);
         scrie_hex(numar mod 16)
      end;
end;

function inl: Pointer;
var
	adresa_stiva_Seg, adresa_stiva_ofs: word;
begin
	asm
   	{ adresa_stiva_seg:= SSeg;}
      mov [bp-6],ss
      { adresa_stiva_ofs := SPtr;}
      mov [bp-8],sp
   end;
   inl := ptr(adresa_stiva_seg, adresa_stiva_ofs);
end;

function inl1: Pointer;
	InLine(
		$89/$E0/ { MOV AX,SP}
      $8C/$D2); { MOV DX,SS}
function inl2(var adresa_Stiva_seg, adresa_stiva_ofs: word): Pointer;
	InLine(
   	{adresa_stiva_seg := SSeg;}
      $8C/$D2/ { MOV DX,SS}
      $C4/$7E/$F8/ { LES DI,[BP-$08] }
      $26/$89/$15/ { MOV ES:[SI,DX]}
      { adresa_Stiva_ofs := SPtr;}
      $89/$E0/ { MOV AX,SP}
      $C3/$7E/$FC/ { LES DI,[BP-$04]}
      $26/$89/$05/ { MOV ES:[DI],AX}
      {descarcare stiva}
      $83/$C4/$08); { ADD SP,8}

procedure inl3(var salvare_stiva_curenta: Pointer);
var
	adresa_stiva_seg, adresa_stiva_ofs: word;
begin
	asm
   	{adresa_stiva_seg := SSeg;}
		mov [bp-2],ss
      {adresa_stiva_ofs:=SPtr;}
      mov[bp-4],sp
   end;
   salvare_stiva_curenta := ptr(adresa_stiva_seg, adresa_stiva_ofs);
end;

procedure inl4(var adresa_Stiva_seg, adresa_stiva_ofs: word;
					var salvare_Stiva_curenta: Pointer);
begin
	asm
   	{adresa_stiva_seg := SSeg;}
      mov dx,ss
      les di, adresa_stiva_seg
      mov es:[di],dx
      {adresa_stiva_ofs := SPtr;}
      mov ax,sp
      les di,adresa_stiva_ofs
      mov es:[di],ax
      {salvare_stiva_curenta:= ptr(adresa_stiva_seg, adresa_stiva_ofs);}
      les di,salvare_Stiva_curenta
      mov es:[di],ax
      mov es:[di+2],dx
   end
end;

begin
	write('Apel functie "obisnuita" = ');
   stiva_curenta := inl;
   scrie_hex(Seg(stiva_curenta^));
   write(':');
   scrie_hex(Ofs(stiva_curenta^));
   writeln;

   write('Apel functie "inline" fara parametri => ');
   stiva_curenta := inl1;
   scrie_hex(Seg(stiva_curenta^));
   write(':');
	scrie_hex(Ofs(stiva_curenta^));
   writeln;

   write('Apel functie "inline" cu parametri => ');
   stiva_curenta := inl2(stiva_seg,stiva_ofs);
   scrie_hex(Seg(stiva_curenta^));
   write(':');
   scrie_hex(Ofs(stiva_curenta^));
   writeln;

   write('Apel procedura "obisnuita" => ');
   inl3(stiva_curenta);
   scrie_hex(Seg(stiva_curenta^));
   write(':');
   scrie_hex(Ofs(stiva_curenta^));
   writeln;

   write('Apel procedura "obisnuita" cu parametri = ');
   inl4(stiva_seg,stiva_ofs,stiva_curenta);
   scrie_hex(Seg(stiva_curenta^));
   write(':');
	scrie_hex(Ofs(stiva_curenta^));
   writeln;

   write('Utilizare directiva asm => ');
   asm
   	mov stiva_seg,ss
      mov stiva_ofs,sp
   end;
   stiva_principala := ptr(stiva_seg,stiva_ofs);
   scrie_hex(Seg(stiva_principala^));
   write(':');
   scrie_hex(Ofs(stiva_principala^));
   writeln;
   write('Afisare pozitie stiva curenta = ');
   scrie_hex(SSeg);
   write(':');
   scrie_hex(SPtr);
   writeln;
end.
