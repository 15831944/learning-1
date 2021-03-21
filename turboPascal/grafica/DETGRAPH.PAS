program ExempluDetectGraph;
uses Graph;
var
	GraphDriver, GraphMode, GraphError: integer;
begin
	DetectGraph(GraphDriver,GraphMode);
	if GraphDriver in [EGA,EGA64,EGAMono, VGA] then
   begin
   	GraphDriver := CGA;
      GraphMode := CGAHI;
   end;
   InitGraph(GraphDriver,GraphMode,'H:\TP\BGI');
   GraphError := GraphResult;
   if GraphError <> grOk then
   begin
   	writeln('Eroare: ', GraphErrorMsg(GraphError));
   end
   else
   	begin
      	{aici desenam ceva}
         CloseGraph;
      end
end.