program SIRMED;
type
	sir_car = string[6];
var
	suma, numar, x, cod: integer;
   sir: sir_Car;
   sfirsit: boolean;
begin
   suma := 0;
   numar := 0;
   sfirsit := false;
   repeat
   	readln(sir);
      if sir  = ''
      	then
         	sfirsit := true
      	else
         	begin
            	val (sir, x, cod);
               if cod > 0
               	then
                  	writeln('^', cod, 'Eroare')
                  else
                  	begin
                  		suma:= suma  + x;
	                     numar := numar +1
   	               end
            end
   until sfirsit;
   if numar = 0
   	then
      	writeln('Nici o valoare')
      else
      	writeln('Media celor', numar, ' valori corecte este', suma/numar)
end.