program Graph_01;
{ deseneaza graficul functiei
F(X) = (Sin(X)+0.5*Sin(3*X))*Exp(-X) pe intervalul -PI/2,7*PI/2 }
uses
	Dos, Graph;
const
	CGA_Netru = 0;
   CGA_Verde = 1;
   CGA_Rosu = 2;
   CGA_Galben = 3;
var
   gXmin,gXmax,gYmin,gYmax: Integer;
   gMaxColor: Integer;
   gResult: Integer;
   gDriver: Integer;
   gMode: Integer;
   gX0,gX1,gY0,gY1: Integer;

{Dreptunghi de incadrare pentru grafic}
function F(X: Real): Real;
begin
	F:=(Sin(X)+0.5*Sin(3*X))*Exp(-01*X);
end;

procedure AflaExtreme(Xmin,Xmax: Real; NrDePasi: Integer;
		var Ymin,Ymax:Real);
var
	I:Integer; {contor de pasi}
   X:Real; {argument curent F(X)}
   Y:Real; {valoare curenta F(X)}
begin
	Ymin:= F(Xmin);
   Ymax:= Ymin;
	for I:= 1 to NrDePasi do
   begin
   	X:=Xmin + I*(Xmax-Xmin)/NrDePasi;
      Y:=F(X);
      if Y < Ymin then
      	Ymin:= Y
      else if Y > Ymax then
      	Ymax := Y
   end;
end;

procedure ScrieLimite(Xmin,Xmax,Ymin,Ymax: Real;
				gX0,gY0,gX1,gY1: Integer);
{ inscrie limitele atinse de funtie si limitele intervalului Xmin, Xmax.
Graficul este incadrat intr-un dreptunghi cu limitele gX0gX1,gY0gY1}
var
	TempStr: string[7];
begin
	SetColor(CGA_Rosu);
   SetTextStyle(DefaultFont,HorizDir,1);
   SetTextJustify(RightText,CenterText);
   SetLineStyle(DashedLn,0,NormWidth);
   MoveTo(gX0,gY0);
   LineRel(-3*TextWidth('-'),0);
   Str(Ymax:6:3,TempStr);
   OutText(TempStr + ' ');
   MoveTo(gX0,gY1);
   LineRel(-3*TextWidth('-'),0);
   Str(Ymin:6:3,TempStr);
   OutText(TempStr + ' ');
   MoveTo(gX0,gY1);
   LineRel(-3*TextWidth('-'),0);
   Str(Ymin:6:3,TempStr);
   OutText(TempStr + '');
   MoveTo(gX0,gY1);
   LineRel(0,2*TextHeight(''));
   MoveRel(0,TextHeight(''));
   SetTextJustify(LeftText,TopTExt);
   Str(Xmin:7:4,TempStr);
	OutText(TempStr);
   MoveTo(gX1,gY1);
   LineRel(0,2*TextHeight(''));
   MoveRel(0,TextHeight(''));
   SetTExtJustify(RightText,TopText);
   Str(Xmax:7:4,TempStr);
   OutText(TempStr);
end;

procedure Conversie(X,Y: Real; Xmin,Ymin,Xmax,Ymax: Real;
		gX0,gY0,gX1,gY1: Integer; var iX,iY: Integer);
{converteste coordonatele utilizator X,Y ale unui punct din
dreptunghiul XminXmax,YminYmax in coordonate ecran relative la
dreptunghiul gX0gX1,gY0gY1}
var
   DeltaX,DeltaY: Real;
   DeltaXEcran,DeltaYEcran: Integer;
begin
	DeltaX:= Xmax - Xmin;
   DeltaY:= Ymax -Ymin;
   DeltaXEcran:= gX1 - gX0;
   DeltaYEcran:= gY1 - gY0;
   IX:=Round((X-Xmin)/DeltaX*DeltaXEcran);
   IY:=DeltaYEcran - Round((Y-Ymin)/DeltaY*DeltaYEcran);
end;

procedure DeseneazaGrafic(Xmin,Xmax: Real; gX0,gY0,gX1,gY1: Integer);
const
	NrDePasi = 100;
var
	I: Integer;
   IX,IY: Integer;
   X,Y: Real;
   Ymin,Ymax: Real;
   FereastraVeche: ViewPortType;
begin
   AflaExtreme(Xmin,Xmax,NrDePasi,Ymin,Ymax);
   GetViewSettings(FereastraVeche);
   SetViewPort(gX0,gY0,gX1,gY1,True);
   SetLineStyle(SolidLn,0,ThickWidth);
   SetColor(CGA_Galben);
   Y:=F(Xmin);
   Conversie(Xmin,Y,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
   MoveTo(IX,IY);
   for I:= 1 to NrDePasi do
   begin
   	X:=Xmin + (Xmax- Xmin)*I/NrDePasi;
      Y:=F(X);
      Conversie(X,Y,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
      LineTo(IX,IY);
   end;
   SetColor(CGA_Rosu);
   SetLineStyle(SolidLn,0,NormWidth);
   {deseneaza axa X}
   Conversie(Xmin,0,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
   MoveTo(IX,IY);
   Conversie(Xmax,0,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
   LineTo(IX,IY);
   {deseneaza axa Y}
	Conversie(0,Ymin,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
   MoveTo(IX,IY);
   Conversie(0,Ymax,Xmin,Ymin,Xmax,Ymax,gX0,gY0,gX1,gY1,IX,IY);
   LineTo(IX,IY);
   {restaureaza  fereastra veche}
   with FereastraVeche do
   	SetViewPort(X1,Y1,X2,Y2,Clip);
   ScrieLimite(Xmin,Xmax,Ymin,Ymax,gX0,gY0,gX1,gY1);
end;

procedure InitializareSistemGrafic;
{Trece ecranul in mod grafic. Stabileste valorile pentru variabilele globale
gXmin,gYmax si gMaxColor}
begin
	gDriver := CGA;
   gMode := CGAC0;
   InitGraph(gDriver,gMode,'H:\TP\BGI');
   gResult := GraphResult;
   if gResult = grOk then
   begin
     gXmin:= 0;
     gXmax:=GetMaxX;
     gYmin:=0;
     gYmax:=GetMaxY;
     gMaxColor:=GetMaxColor;
   end;
end;

procedure DreptunghiDeIncadrare(var gX0,gY0,gX1,gY1:Integer);
{stabileste limitele si deseneaza dreptunghiul de incadrare pentu graficul de functie}
begin
	gX0:=Round(gXmin+(gXmax-gXmin)*4/16);
   gX1:=Round(gXmin+(gXmax-gXmin)*15/16);
   gY0:=Round(gYmin+(gYmax-gYmin)*2/16);
   gY1:=Round(gYmin+(gYmax-gYmin)*11/16);
   {Dreptunghiul de incadrare se deseneaza cu vede si cu line punctata}
   SetLineStyle(DottedLn,0,NormWidth);
   SetColor(CGA_Verde);
   Rectangle(gX0,gY0,gX1,gY1);
end;

procedure AntetPagina(Formula: string);
var
	XMijloc: Integer;
begin
	SetColor(CGA_Galben);
   XMijloc:=gXmin+(gXmax-gXmin) div 2;
   SetTextStyle(TriplexFont,HorizDir,1);
   SetTextJustify(CenterText,TopText);
   OutTextXY(XMijloc,gYmin,'Demonstratie Graph');
   SetTextJustify(CenterText,CenterText);
   OutTextXY(XMijloc,gYmax-TextHeight(''),Formula);
end;

begin
	InitializareSistemGrafic;
   if gResult <> grOk then
   begin
   	writeln('Eroare de initializare sistem grafic: ',gResult);
      writeln('(',GraphErrorMsg(gResult),')');
      Halt(1);
   end;
   DreptunghiDeIncadrare(gX0,gY0,gX1,gY1);
   AntetPagina('(sin x + 0.5 sin 3x) exp(-x/10)');
   DeseneazaGrafic(-Pi/2,7*Pi/2,gX0,gY0,gX1,gY1);
   ReadLn;
   CloseGraph;
end.