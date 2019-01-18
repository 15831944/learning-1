program AmplaseazaDomino;
uses WinDos, WinCrt;
const MaxN=10;
type poz=record
     x,y:byte;
     end;
var a:array[1..MaxN,1..MaxN] of 0..1;
    domino:array[1..2] of poz;
    n,m,i,j:byte;
function final: boolean;
var k,g: byte;
begin
     for k:=1 to n do
         for g:=1 to m-1 do
             if(a[k,g]=0) and (a[k,g+1]=0) then
             begin
                  final:=false;
                  exit;
             end;
     for k:=1 to n-1 do
         for g:=1 to m do
             if(a[k,g]=0) and (a[k+1,g]=0) then
             begin
                  final:=false;
                  exit;
             end;
     final:=true;
end;

begin
     clrscr;
     write('n m:');readln(n,m);
     if not(odd(n) and odd(m)) then
     begin
          writeln('A nu are strategie sigura de cistig.');
{          exit;}
     end
     else
     writeln('A are strategie sigura de cistig.');
     for i:=1 to n do
        for j:=1 to m do a[i,j]:=0;
     while not(final) do
     begin
        for i:=1 to 2 do
        begin
           write('Introduceti coordonatele celei de a ',i,' casute hasurate de B:');
           readln(domino[i].x,domino[i].y);
           a[domino[i].x,domino[i].y]:=1;
        end;
        write('A hasureaza casutele: ');
        for i:=1 to 2 do
        begin
           write('(',n+1-domino[i].x,',',m+1-domino[i].y,')');
           a[n+1-domino[i].x,m+1-domino[i].y]:=1;
        end;
        writeln;
     end;
     readln;
end.