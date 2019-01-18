function ec_diff()
    function yprim=func(x,y)
        yprim=zeros(2,1);
        yprim(1)=y(1).*(1-y(2).^2)-y(2);
        yprim(2)=y(1);
    end
t0=0;
tf=20;
x0=[0 0.25];
[t x]=ode23(@func,[t0 tf],x0);
plot(t,x(:,1),'--g',t,x(:,2),'-r');
grid;
end