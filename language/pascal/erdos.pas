{ teorema lui erdos }
program erdos;
var
	mat:array[0..150,1..150] of word;
	nc:array[0..150] of word;
	m,n,contor,x,i,j,n1:word;
function divid(i,x:word):word;
var k:word;
begin
	k:=1;
	while( k <=nc[i]) and (x mod mat[i,k] <> 0)
	do inc[k];
	divid:=k mod[nc[i]+1];
end;
procedure b(i:world);
var k: world;
begin
	for k:=1 to nc[i] do write(mat[i,k]:5);
	writeln(x:5); halt;
end;
procedure a(i,x:word);
var k:word;
begin
	if i=0 then write(x:5)
	else begin
		a(i-1, mat[i,divid(i,x)]);
		write(x:5);
	end;
end;
procedure scrie;
var i,j: word;
begin
	for i:=1 to n1 do
	begin
		for j:=1 to nc[i] do write(mat[i,j]:5);
		writeln;
	end;
end;

begin{main}
	writeln;
	write('m='); readln(m);
	writeln('n=');readln(n);
	n1:=0;
	nc[0]:=1;
	mat[0,1]:=1;
	for i:=1 to m do nc[i]:=0;
	for contor:=1 to (m-1)*(n-1)+1 do
	begin
		scrie;
		readln(x);
		i=n1;
		while divid(i,x)=0 do dec(i);
		if i= n1 then
			if n1=m-1 then
			begin
				writeln('este satisfacuta conditia a)');
				a(i,x);
				writeln;
				halt;
			end
			else begin
				inc(n1);
				nc[n1]:=1;
				mat[n1,1]:=x
			end
		else if nc[i+1]=n-1 then
		begin
			writeln('cond b');
			b(i+1);
		end
		else begin
			inc(nc[i+1]);
			mat[i+1,nc[i+1]]:=x;
			end
	end;
end.