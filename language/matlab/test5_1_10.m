function test5_1_10
%this is the example 5.1.10 from MATLAB book
%it computes the sinus function with step=0.1
a=-2*pi;
b=2*pi;
c=0.1;
n=a:c:b;
k=max(size(n));
for i=1:k
    x(i)=sin(n(i));
end
plot(n,x);
grid;
title('Graphic of the sinus function with step=0.1');