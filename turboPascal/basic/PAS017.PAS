program selectie;
uses CRT;
var
   punctaj1, punctaj2, punctaj3: integer;
begin
     clrscr;
     write('Ce punctaj are primul candidat:');
     readln(punctaj1);
     clrscr;
     write('Ce punctaj are al doilea candidat:');
     readln(punctaj2);
     clrscr;
     write('Ce punctaj are al treilea candidat:');
     readln(punctaj3);
     clrscr;
     if punctaj1 >= punctaj2
        then
            if punctaj1 >= punctaj3
               then
                   writeln('Optam pentru primul candidat',
                   ' care a obtinut ',punctaj1,' puncte')
               else
                   writeln('Optam pentru al treilea candidat',
                   ' care a obtinut ',punctaj3,' puncte')
        else
            if punctaj2 >= punctaj3
               then
                   writeln('Optam pentru al doilea candidat',
                   ' care a obitnut ', punctaj2, ' puncte')
               else
                   writeln('Optam pentru al treilea candidat',
                   ' care a obtinut ', punctaj3,' puncte');
end.