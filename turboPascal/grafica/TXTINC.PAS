program prgtextIncadrat;
uses
	Crt,Graph;
var
	Driver, Mode:Integer;

procedure TextIncadrat (Mesaj: string; X1,Y1,X2,Y2: Integer);
var
	MulX,DivX,MulY,DivY: Word;
   AttributeText: TextSettingsType;
begin
	MulX:=100;
   DivX:=100;
   MulY:=100;
   DivY:=100;
   GetTextSettings(AttributeText);
	SetTextStyle(AttributeText.Font,HorizDir,UserCharSize);
   SetTextJustify(LeftText,TopText);
   SetUserCharSize(MulX,DivX,MulY,DivY);
   while TextHeight(Mesaj) < Y2 -Y1 do
   begin
   	MulY:=Round(MulY*1.1);
      SetUsercharSize(MulX,DivX,MulY,DivY);
   end;
   while TextHeight(Mesaj) < Y2 -Y1 do
   begin
   	DivY:=Round(DivY*1.1);
      SetUserCharSize(MulX,DivX,MulY,DivY);
   end;
   while TextWidth(Mesaj) < X2-X1 do
   begin
   	MulX:=Round(MulX*1.1);
		SetUserCharSize(MulX,DivX,MulY,DivY);
   end;
   while TextWidth(Mesaj) < X2-X1 do
   begin
   	DivX:=Round(DivX*1.1);
      SetUserCharSize(MulX,DivX,MulY,DivY);
   end;
   OutTextXY(X1+(X2-X1-TextWidth(Mesaj)) div 2, Y1 +(Y2-Y1 -TextHeight(Mesaj)) div 2, Mesaj);
   Rectangle(X1,Y1,X2,Y2);
   with AttributeText do
   begin
   	SetTExtStyle(Font,Direction, CharSize);
      SetTExtJustify(Horiz,Vert);
   end
end;

begin
	Driver:=Detect;
   InitGraph(Driver,Mode,'h:\TP\bgi');
   if GraphResult <> grOk then
   	Halt(1);
   TextIncadrat('TEXTS',10,10,100,100);
   repeat until ReadKey = #13;
   CloseGraph;
end.