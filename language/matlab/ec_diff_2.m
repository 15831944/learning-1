function ec_diff_2()
    function yp=func(x,y)
        yp=zeros(2,1);
        ydm=-y(2);
        yp(1)=ydm;
        yp(2)=y(1);
    end
x0=0;
xf=2*pi;
y0=[1; 0];
[x y]=ode23(@func,[x0 xf],y0);
z=sin(x);
plot(x,y,x,z,'o');
grid;
end