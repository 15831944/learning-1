program putere2;
type:
	max = 0..20;
	mat = array[max,max] of real;
	vect = array[max] of 0..1;
var:
	a,b,cd :mat;
	vm : vect;
	p : array[max] of 0..1
	n,u,j,k,l,rv,s : max;
	m : byte;
procedure writemat(var A: mat);
begin
	for i:= 1 to n do
		begin
			for j:=1 to n do
				write('',a[i,j]:8:2);
			writeln;
		end;
end;
procedure prodmat(A,B: mat; var c : mat)
begin
	for i:=1 to n do
	for j:=1 to n do
	begin
		c[i,j] :=0;
		for k:=1 to n do
			c[i,j] := c[i,j]+a[i,k]*b[k,j];
	end;
end;
procedure binar(var vm:vect, var r max; m:byte);
begin
	r:=0;
	repeat
		r:=r+1;
		vm[r]:=m mod 2;
		m: mdiv 2;
	until m=0;
end;
procedure a_la_M(a: mat; var b :mat; m:byte);
begin
	binar(vm, r, m);
	for i:=1 to n do
	for j:=1 to n do
	begin
		b[i,j]:=0;
		b[i,i]:=1;
	end;
	d:=a;
	for v:=1 to r do
	begin
		if vm[v]=1 then
		begin
			prodmat(b,d,c);
			b:=c;
		end;
		prodmat(b,d,c);
		d:=c;
	end;
end;
begin{ main}
	write('Dimensiunea matricii A este N=');
	readln(n);writeln(n);
	writeln('Matricea A este ');
	for i:=1 to n do
	for j:=1 to n do
		read(a[i,j]);
	writemat(a);
	write('Puterea la care este ridicata matricea ');
	readln(m); writeln(m);
	a_la_M(a,b,m);
	writeln('Matricea A la puterea ', m, ' este ');
	writeln;
	writemat(b);
end.