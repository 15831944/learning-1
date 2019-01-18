function ec_diff_1()
    function yp=func(x,y)
        yp=zeros(5,1);
        yp(1)=0;
        yp(2)=y(1);
        yp(3)=y(2);
        yp(4)=y(3);
        yp(5)=y(4);
    end
x0=0;
xf=02;
y0=[1;0;-1;0;1];
[x y]=ode23(@func,[x0 xf],y0);
z=1-(1/2).*x.^2+(1/24).*x.^4;
plot(x,y(:,5),'o',x,z);
grid;
end