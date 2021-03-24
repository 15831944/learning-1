program aspectRatio;
uses
	Crt, Graph;
var
	Driver, Mode: Integer;
   XCentru, YCentru: Integer;
	PixelX, PixelY: Word;
   X,Y: Real; {coordonatele virfului curent}
   Raza: Integer;
   Cod: Integer;
   Culoare, Fond: Integer;
   Optiune: Char;
begin
	Driver := Detect;
   InitGraph(Driver,Mode,'h:\TP\bgi');
   Cod := GraphResult;
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
   Raza := GetMaxY div 3;
	SetBkColor(0);
   SetTextJustify(LeftText,TopText);
   SetTextStyle(DefaultFont, HorizDir,1);
   repeat
   	GetAspectRatio(PixelX,PixelY);
      SetColor(Culoare);
      Circle(XCentru,YCentru,Raza);
		OutTextXY(0,0,'Diametrul orizontal e mai mare ? -> X');
      OutTextXY(0,8,'Diametrul vertical e mai mare ? -> Y');
      OutTextXY(0,16,'Diametrele sunt egale ? -> ENTER');
      Optiune := ReadKey;
      SetColor(0);
   	Circle(XCentru,YCentru,Raza);
      case UpCase(Optiune) of
      	'X': SetAspectRatio(PixelX,Round(PixelY*1.1));
         'Y': SetAspectRatio(Round(PixelX*1.1),PixelY);
      end;
   until Optiune = #13;
   CloseGraph;
end.