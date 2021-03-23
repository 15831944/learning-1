program DEmonstratieXorPut;
uses
	Crt,Graph;
const
	ENTER = #13;
var
	Driver, Mode: Integer;
   X,Y: Integer;
   Xnou,Ynou: Integer;
   LaturaX,LaturaY: Integer;
   Xmin,Xmax: Integer;
   Ymin,Ymax: Integer;
   Ch: Char;
procedure DeseneazaCursor(XCentru, YCentru: Integer);
{deseneaza un cursor in cruce cu centru in puctul (XCentru,YCentru)}
begin
	MoveTo(XCentru,YCentru);
   LineRel(LaturaX,0);
   MoveTo(XCentru,YCentru);
   LineRel(-LaturaX,0);
   MoveTo(XCentru,YCentru);
   LineRel(0,LaturaY);
   MoveTo(XCentru,YCentru);
   LineRel(0,-LaturaY);
end;
begin
	Driver:= Detect;
   InitGraph(Driver,Mode,'H:\TP\bgi');
   if GraphResult <> grOk then
   	Halt(1);
   LaturaX := (GetMaxX +1) div 50;
   LaturaY := (GetMaxY +1) div 50;
   Xmin := LaturaX;
   Xmax := GetMaxX - LaturaX;
   Ymin := LaturaY;
   Ymax := GetMaxY - LaturaY;
	X:= Xmin + Random(Xmax - Xmin +1);
   Y:= Ymin + Random(Ymax - Ymin +1);
   SetColor(GetMAxColor);
   SetWriteMode(XorPut);
   repeat
   	DeseneazaCursor(X,Y);
      repeat
      	Xnou := X -LaturaX + Random(2*LaturaX +1);
         Ynou := Y - LaturaY + Random(2*LaturaY+1);
      until (Xmin <= Xnou) and(Xnou <=Xmax) and(Ymin <= Ynou) and (Ynou <= Ymax);
      DeseneazaCursor(X,Y);
      if KeyPressed then
      	Ch:= ReadKey
      else
      	Ch:= ' '
   until Ch = ENTER;
   CloseGraph;
end.