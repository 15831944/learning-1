function ex_grad(f,xp,yp,sx,sy)
[x y]=meshgrid(xp,yp);
z=eval(f);
[px py]=gradient(z,sx,sy);
contour(x,y,z);
hold on;
quiver(x,y,px,py,1.5,'g');
hold off;