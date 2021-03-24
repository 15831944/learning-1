program spiridus;
uses
	Crt,Graph;
var
	Driver,Mode: Integer;
   Latime,Inaltime: Integer;
   X,Y,Xnou,Ynou: Integer;
   DimX,DimY: Word;
   DimensiuneMemorie: Word;
   BufferImagine: ^Byte;

procedure DeseneazaSpiridus(X1,Y1,X2,Y2 : Integer);
var
	ModulY: Integer;
begin
	SetViewPort(X1,Y1,X2,Y2,ClipOn);
   X1:=X2-X1;
   Y1:=Y2-Y1;
   ModulY:= Y1 div 5;
   Circle(X1 div 2, ModulY div 2, ModulY div 2);
   Line(X1 div 2, ModulY, X1 div 2, 3* ModulY);
   Line(X1 div 2, ModulY, 0, 3*ModulY);
   Line(X1 div 2, ModulY, X1, 3* ModulY);
   Line(X1 div 2, 3 * ModulY, X1,Y1);
   SetViewPort(0,0,GetMaxX,GetMaxY,ClipOn);
end;

begin
	Driver := Detect;
   InitGraph(Driver, Mode, 'H:\TP\bgi\');
   if GraphResult <> grOk then
   	Halt;
   GetAspectRatio(DimX,DimY);
   Inaltime := (GetMaxY + 1) div 10;
   Latime := Round(Inaltime *(DimY/DimX)*1/2);
   DeseneazaSpiridus(0,0,Latime,Inaltime);
   DimensiuneMemorie := ImageSize(0,0,Latime,Inaltime);
   if DimensiuneMemorie = 0 then
   begin
   	CloseGraph;
      Halt;
   end;
   GetMem(BufferImagine,DimensiuneMemorie);
   GetImage(0,0,Latime,Inaltime,BufferImagine^);
   X:= 0;
   Y:=0;
   repeat { plimbare spiridus pe ecran}
   	repeat
      	Xnou := X + (Random(3) -1) * Random(Latime div 5);
         Ynou := Y + (Random(3) -1) * Random(Inaltime div 10);
      until (0 <= Xnou) and (Xnou <=GetMaxX - Latime) and (0 <= Ynou)
			and (Ynou <= GetMAxY - Inaltime);
      PutImage(X,Y, BufferImagine^,XorPut);
      X:= Xnou;
      Y:= Ynou;
      PutImage(X,Y,BufferImagine^, XorPut);
   until KeyPressed;
   repeat until ReadKey = #13;
   CloseGraph;
end.