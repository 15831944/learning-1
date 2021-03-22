program culori;
uses Graph;
var
	Driver, Mode: Integer; { placa grafica si modul grafic}
   CuloareGrafic: Integer; { culoare folosita pentru grafic}
	CuloareDreptunghi: Integer; { culoare folosita pentru dreptunghi}
	CuloareExtreme: Integer; {culoare folsoita pt valori extreme x,y}
   CuloareTitlu: Integer; {culoare pentru titlul paginii si formula}
begin
	Driver = Detect;
   InitGraph(Driver,Mode,'');
   if GraphREsult <> grOk then
   	Halt(1)
   { daca avem o placa CGA alege modul CGAC0}
	if Driver = CGA then
		SetGraphMode(CGAC0)
	{alege culorile in functie de modul grafic}
	case Driver of
		CGA: begin
				CuloareGrafic := 3;
				CuloareDreptunghi := 2;
				CuloareExtreme := 2;
				CuloareTitlu := 1;
		     end;
		EGA,
		VGA: begin
				CuloareGrafic := Yellow;
				CuloareDreptunghi := Red;
            CuloareExtreme := Red;
            CuloareTitlu := Green;
           end;
      else
      	begin
         	CuloareGrafic := 1;
            CuloareDreptunghi := 1;
				CuloareExteme := 1;
            CuloareTitlu := 1;
         end;
   end;
   {...alte initializari}
   {deseneaza imaginea dorita}
   SetColor(CuloareDreptunghi);
   {... deseneaza dreptunghiul de incadrare}
   SetColor(CulaoreGrafic);
   {... deseneaza graficul de functie }
   SetColor(CuloareExtreme);
   {... inscrie valorile extreme}
   SetColor(CuloareTitlu);
   {... afiseaza titlu paginii si farmula functie}
   {inchide sistemul grafic}
   CloseGraph;
end.