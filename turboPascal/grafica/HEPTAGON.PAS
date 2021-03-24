program heptagon;
{ deseneaza un heptagon rosu pe fornd galben in centrul ecranului}
uses
	Crt, Graph;
const
	NumarDeVirfuri = 7;
	ENTER = #$0D;
var
	Driver, Mode: Integer;
   XCentru, YCentru: Integer;
   RazaX, RazaY: Integer;
	PixelX, PixelY: Word;
   X,Y: Real; {coordonatele virfului curent}
   Virf: Integer;
   Cod: Integer;
   Culoare, Fond: Integer;
   UnghiInitial: Real;
   latura: Integer;
begin
	Driver := Detect;
   InitGraph(Driver,Mode,'h:\TP\bgi');
   Cod := GraphREsult;
   if Cod <> grOk then
   begin
   	writeln('Eroare ', Cod,' (',GraphErrorMsg(cod),')');
      Halt(1);
   end;
   case Driver of
   	CGA:
			begin
      		SetGraphMode(CGAC0);
            Culoare := 2;
            Fond:=Yellow;
      	end;
      HercMono:
      	begin
         	Culoare:=1;
            Fond := 0;
         end;
      EGA,VGA:
      	begin
				Culoare := Red;
            Fond := Yellow;
         end;
   else
    	Culoare := 1;
      Fond := 0;
   end;
	XCentru := GetMaxX div 2;
	YCentru := GetMaxY div 2;
   GetAspectRatio(PixelX,PixelY);
   RazaY:= GetMaxY div 2;
   RazaX := Round(PixelY/PixelX*RazaY);
   SetBkColor(Fond);
   SetColor(Culoare);
   SetLineStyle(SolidLn,0,ThickWidth);
   MoveTo(XCentru, YCentru - RazaY);
   UnghiInitial := Pi/2;
   for latura := 1 to NumarDeVirfuri do
   begin
		X:= XCentru + RazaX*Cos(UnghiInitial + latura*2*Pi/NumarDeVirfuri);
      Y:= YCentru - RazaY*Sin(UnghiInitial + latura*2*Pi/NumarDeVirfuri);
      LineTo(Round(X), Round(Y));
   end;
   repeat until ReadKey = ENTER;
   CloseGraph;
end.