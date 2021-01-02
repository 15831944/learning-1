program comun2;
const
	max_elem = 10;
type
	cazuri = (constant, cresc, desc, neord);
   val_indice = 0..max_elem;
   vector = array[val_indice] of integer;
var
	a,b,c: vector;
   na,nb,indice: val_indice;
   tip: cazuri;
   ic: val_indice;

procedure citeste_vector(var x: vector; var numar: val_indice;car: char);
var
	i: integer;
begin
	i:= 0;
   repeat
   	i:= i+1;
      write('',car,'[',i:2,'] =');
      readln(x[i]);
   	if (i mod 5) = 0 then
      	writeln;
   until (x[i] < 0) or (i >= max_elem);
	if x[i] < 0 then
   	numar:= i-1
   else
   	numar:= i;
   writeln;
end;

procedure afiseaza(x: vector; numar: val_indice);
var
	i: val_indice;
begin
	for i:=1 to numar do
   begin
   	write(' x[',i:2,'] =',x[i]);
      if (i mod 5) = 0 then
      	writeln;
   end;
end;

function gasit(x: vector; numar: val_indice; elem: integer): boolean;
var
	i: integer;
begin
	i:= 1;
   while(x[i] <> elem) and (i < numar) do
   	i:= i + 1;
   gasit:= x[i] = elem;
end;

function tip_ord(x: vector; numar: val_indice): cazuri;
var
	ord_cresc, ord_desc: boolean;
   i: integer;
begin
	ord_desc:= true;
   ord_cresc:= true;
   i:= 0;
   while (ord_cresc or ord_desc) and (i < numar -1) do
   begin
   	i:= i+1;
      if x[i] > x[i+1] then
      	ord_cresc:=false;
      if x[i] < x[i+1] then
      	ord_desc:= false;
   end;
   if ord_cresc and ord_desc then
		tip_ord:= constant {sir constant}
   else
   	if ord_cresc then
      	tip_ord:= cresc { sir crescator }
      else
      	if ord_desc then
         	tip_ord:= desc { sir descrescator }
         else
         	tip_ord:= neord {sir neordonat }
end;

function cautare_bin(x: vector; numar: val_indice; valoare: integer): boolean;
var
	inferior,superior, mijloc: integer;
begin
	inferior:=1;
   superior:= numar;
   mijloc:= (inferior + superior) div 2;
   while(valoare <> x[mijloc]) and ((superior -inferior) >1) do
   begin
   	if (tip = cresc) and (valoare < x[mijloc])
			or (tip=desc) and (valoare>x[mijloc]) then
			superior:=mijloc
      else
      	inferior:=mijloc;
      mijloc:=(inferior+superior) div 2;
   end;
	if x[mijloc] <> valoare then
   begin
   	if x[superior] = valoare then
      	mijloc:= superior;
      if x[inferior] = valoare then
      	mijloc:= inferior;
   end;
   cautare_bin:=x[mijloc] = valoare;
end;

procedure construieste(x,y: vector; nx,ny: val_indice; var numar: val_indice);
	procedure memoreaza;
   begin
   	if (not gasit(c,numar,x[indice])) or (numar = 0) then
      begin
      	numar:= numar +1;
         c[numar]:=x[indice];
      end;
   end;
begin
 	numar:=0;
   for indice:= 1 to nx do
    	case tip of
			constant:
           	if x[indice] = y[1] then
              	memoreaza;
         desc,cresc:
           	if cautare_bin(y,ny,x[indice]) then
              	memoreaza;
         neord:
           	if gasit(y,ny,x[indice]) then
              	memoreaza;
  		end;
end;

{program principal }
begin
	citeste_vector(a,na,'a');
   citeste_vector(b,nb,'b');
   tip:=tip_ord(a,na);
   if tip = neord then
	   begin
   		tip:=tip_ord(b,nb);
   	   construieste(a,b,na,nb,ic);
	   end
	else
   	construieste(b,a,nb,na,ic);
   writeln;
   if ic <> 0 then
   	begin
      	writeln('Elementele comune sunt:');
         writeln;
         afiseaza(c,ic);
      end
   else
   	writeln('Nu exista elemente comunte');
end.