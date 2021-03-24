{ se testeaza cu N=3,T=90,K=54,S=3,Q=0.1547}
program poly;
uses
	Crt, Graph;
var
	Driver, Mode:Integer;
   N: Integer;
   T: Integer;
   K: Integer;
   I: Integer;
   S: Integer;
   Q: Real;
   R1,R2,DR,R: Real;
procedure DeseneazaPoligonRegulat(NumarVirfuri, XCentru, YCentru: Integer;Raza: Real; Theta0: Real);
{deseneaza un poligon  regulat cu NumarVirfuri laturi, centrul in
(XCentru, YCentru), raza cercului circumscris egala cu Raza*H si
primul virf plasat pe cerc la Theta0 grade}
type
	PointArray = array[1..1000] of PointType;
var
	DimX,DimY: Word;
	RazaX, RazaY: Integer;
	TabVirfuri: ^PointArray;
	Unghi: Real;
	Virf: Integer;
begin
	GetAspectRatio(DimX,DimY);
	RazaY:= Trunc(GetMaxY*Raza);
	RazaX:= Round(RazaY*DimY/DimX);
	Theta0 := 2*Pi/360*Theta0;
	GetMem(TabVirfuri,(NumarVirfuri +1)*SizeOf(PointType));
	for Virf:=1 to NumarVirfuri +1 do
   	with TabVirfuri^[Virf] do
		begin
      	Unghi:=Theta0 + Virf*2*Pi/NumarVirfuri;
         X:=XCentru + Round(RazaX*Cos(Unghi));
         Y:=YCentru - Round(RazaY*Sin(Unghi));
      end;
   DrawPoly(NumarVirfuri+1,TabVirfuri^);
   FreeMem(TabVirfuri,(NumarVirfuri +1)*SizeOf(PointType));
end;

begin
	write('Numar de virfuri ale poligonului: ');
   readln(N);
   write('Unghiul la centru al primului virf: ');
   readln(T);
   write('Numar de poligoane desenate: ');
   readln(K);
   write('Nr. de laturi rotatie poligon: ');
   readln(S);
   write('Raportul intre ultima si prima raza: ');
   readln(Q);
   Driver:=Detect;
   InitGraph(Driver,Mode,'h:\TP\bgi');
   if GraphResult <> grOk then
   	Halt(1);
   R1:=0.5;
   R2:=R1*Q;
   R:=R1-R2;
   for I:= 0 to K do
   	DeseneazaPoligonRegulat(N,(GetMaxX +1) div 2,
		 (GetMaxY+1) div 2, R2+DR/K*I,
       T+S*360/N/K*I);
   repeat until ReadKey = #13;
   CloseGraph;
end.