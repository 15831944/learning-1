program arbore_binar;
{ genereaza un arbore binar }
uses turtle;
var  level,x0,y0:integer;
     length,limit:real;
procedure tree(level:integer;length:real);
begin if length<limit then                       { point }
               else begin if level=0 then       { point }
                             else begin
                                       for_ward (length);
                                       left(45);
                                       tree(level-1,length/2);
                                       right(90);
                                       tree(level-1,length/2);
                                       left(45);
                                       back(length);
                                  end
                    end
end;
begin   { main }
        writeln(' desenarea unui arbore binar');
        write(' originea reperului (x0,y0): ');
        read(x0,y0);
        write(' level : ');readln(level);
        write(' lenght: ');readln(length);
        write(' limit : ');readln(limit);
        turtle_start;
        set_reper(x0,y0);
        tree(level,length);
        turtle_stop;
end.
