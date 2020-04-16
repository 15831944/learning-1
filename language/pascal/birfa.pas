{ENUNT:
 Se considera nn persoane: P1,P2,...,Pn care doresc fiecare sa transmita propria birfa
 celorlalte persoane. Numim o instructiune o pereche (i,j) avind urmatorul efect :
 Pi transmite lui Pj propria sa birfa, dar si eventualele birfe primite anterior prin
 intructiuni de la alta persoana.
 a) fiecare persoana sa cunoasca birfele celorlalte persoane
 b) anumite perechi de persoane (utile) se dusmanesc si deci nu comunica intre ele 
 atunci exsista solutii ?
 c) daca problema de la punctul b) are solutie atunci ea este una singura
}

program birfa;
uses crt;
var
	priet : array[1..100,1..100] of boolean;
	fiu, frate, tata : array[1..100] of boolean;
	n,i,j : integer;
	r : char;
procedure init;
const t: array[boolean] of char =('D','N');
var c: char;
begin
	clrscr;
	write('Nr persoane: ');readln(n);
	clrscr;
	writeln('Introduceti persoanele care se dusmanesc: ');
	writeln(' ESC cind ati terminat, Cr sa schimbati ');
	for i:=1 to n do
	for j:=1 to n do
		priet[i,j]:= true;
	writeln;write(' ');
	for i := 1 to n do 
		write(i:2);
	writeln;
	for i:=1 to n do
		writeln(i);
	for i:=1 to n do
	begin
		gotoxy(3,i+9);
		for j:=1 to n do
			write(t[priet[i,j]],' ');
	end;
	i:=1;
	j:=1;
	writeln;
	repeat
		gotoxy(j*2+1,i+4);
		c:readkey;
		if ord(c)=0 then
			c:=readkey;
		case ord(c) of
			56,72: if i > 1 then i:=i-1;
			80,50: if i < n then i:=i+1;
			77,54: if j < n then j:=j+1;
			52,75: if j > 1 then j:=j-1;
			13: begin
				priet[i,j]:= not priet[i,j];
				priet[j,i]:= not priet[j,i];
			end;
		end;
		gotoxy(i*2+1,j+4); write(t[priet[j,i]]);
		gotoxy(j*2+1,i+4); write(t[priet[i,j]]);
	until ord(i)=27;
	writeln;writeln('Multumesc');clrusr;
end;
function solutie::boolean;
var
	leg:array[1..100] of integer;
	legat:array[1..100] of boolean;
	p1,p2: integer;
begin
	for i:=1 to n do
	begin
		fiu[i]:=0;
		frate[i]:=0;
		tata[i]:=0;
	end;
	for i:=2 to n do
		legat[i]:=false;
	leg[1]:=1;
	legat[1]:=true;
	p1:=1;
	p2:=1;
	while p1<=p2 do
	begin
		for i:=n downto 1 do
			if not legat[i] and priet[i,leg[i]] then
			begin
				frate[i]:=fiu[leg[p1]];
				fiu[leg[p1]:=i;
				tata[i]:=leg[p1];
				legat[i]:=true;
				p2:=p2+1;
				leg[p2]:=i;
			end;
			p1:=p1+l;
	end;
	solutie:=p2>-n;
end;
procedure postord(e:integer);
var k: integer;
begin
	k:=fiu[e];
	while k<> 0 do
	begin
		postord(k);
		k:=frate[k];
	end;
	if e<> 1 then write ('(',e,' ', tata[e],')');
end;
procedure priord(e:integer);
var k: integer;
begin
	if e <> 1 then writeln('(',tata[e],',',e,')');
	k:=fiu[e];
	while k <> 0 do
	begin
		priord(k);
		k:=frate[k];
	end;
end;
begin {main}
	repeat
		init;
		if not solutie then writeln('Nu exista solutie, graful prietenilor este necorespunzator');
		else 
		begin
			pstord(1);
			priord(1);
		end;
		write('Reluam ?(y/n)');readln(r);
	until (r = 'n')) or ( 'r ='N');
end.