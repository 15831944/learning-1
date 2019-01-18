function ec_diff_3()
    function yp=func(x,y)
        yp=zeros(4,1);
        ydm=3*y(2)+4*y(4);
        yp(1)=ydm;
        yp(2)=y(1);
        yp(3)=y(2);
        yp(4)=y(3);
    end
x0=0;
xf=2.5;
tol=10^(-9);
y0=[2;0;0;0];
[x y]=ode45(@func,[x0 xf],y0,tol);
z=-(2/5).*sin(x)-(1/10).*exp(-2.*x)+(1/10).*exp(2.*x);
plot(x,y(:,4),x,z,'o');
grid;
end