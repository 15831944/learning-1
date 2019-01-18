function movievibes()
load vibesdat;
n=max(size(L1));
nh=fix(n/2);
x=(-nh:nh)/nh;
clear c;
clf;
view(3);
for k=1:12
    eval(['c(k)=L' num2str(k) '(24,13)/3;']);
end
colormap(prism(6));
delt=0.1;
ncadre=10;
M=moviein(ncadre);
for k=1:ncadre
    disp(k);
    t=k*delt;
    s=c.*sin(sqrt(lambda)*t);
    L=s(1)*L1+s(2)*L2+s(3)*L3+s(4)*L4+s(5)*L5+s(6)*L6+...
        s(7)*L7+s(8)*L8+s(9)*L9+s(10)*L10+s(11)*L11+s(12)*L12;
    s=s.*lambda;
    V=s(1)*L1+s(2)*L2+s(3)*L3+s(4)*L4+s(5)*L5+s(6)*L6+...
        s(7)*L7+s(8)*L8+s(9)*L9+s(10)*L10+s(11)*L11+s(12)*L12;
    V(1:nh,1:nh)=NaN*ones(nh,nh);
    cla;
    surfc(x,x,L,V);
    axis([-1 1 -1 1 -1 1]);
    grid;
    M(:,k)=getframe;
end
movie(M,20,10);