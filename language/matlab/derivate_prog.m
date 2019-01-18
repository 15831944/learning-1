function derivate_prog()
x=-3:0.1:4;
f=x.^5-3*x.^4-11.*x.^3+27*x.^2+10*x-24;
df=diff(f)./diff(x);
dx=x(2:length(x));
produs=df(1:length(df)-1).*df(2:length(df));
i=find(produs<0);
p_critic=dx(i);
f_critic=f(i);
dfc=f(3:length(f))-f(1:length(f)-2);
dxc=x(3:length(x))-x(1:length(x)-2);
dy=dfc./dxc;
dxp=x(2:length(x)-1);
pr=dfc(1:length(dfc)-1).*df(2:length(dfc));
p_cr=dxp(find(pr<0)+1);
f_cr=f(find(pr<0)+1);
%ploting
plot(x,f,'g');
grid
hold on;
plot(dx,df,'r');
grid
plot(p_critic,f_critic,'o');
grid
plot(dxp,dy,'g',p_cr,f_cr,'og')
grid
hold off;