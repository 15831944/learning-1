function interpgriddata()
x=-1:.5:1;
y=-1:.5:1;
y=y';
[x,y]=meshgrid(x,y);
z=x.*(x.^2+y.^2);
xi=-1:.1:1;
yi=-1:.1:1;
[xi,yi]=meshgrid(xi,yi);
zi=griddata(x,y,z,xi,yi);
mesh(x,y,z);
hold on;
mesh(xi,yi,zi-5);