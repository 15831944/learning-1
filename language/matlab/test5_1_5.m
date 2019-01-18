function test5_1_5()
%Exemple 5_1_5
a=-10;
b=-4;
c=4;
d=10;
f=0.01; %factorization step
t=a:f:d;
k=max(size(t));
for i=1:k
    if (((t(i)>=a) & (t(i)<b)) | ((t(i)>=c) &(t(i)<=d)))
        y(i)=sin(t(i));
    end
    if ((t(i)>=b) & (t(i)<c))
        y(i)=cos(5*t(i));
    end
end
plot(t,y);