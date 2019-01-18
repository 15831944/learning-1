function X=modul(t,a,b,c)
%Absolute value function with diferent step
%X is output, t is the squence a is left interval,b is the zero point c is right interval.
k=max(size(t));
for i=1:k
    if(t(i)>=a)&(t(i)<b)
        X(i)=abs(t(i));
    end
    if(t(i)>=b)&(t(i)<=c)
        X(i)=t(i);
    end
end
plot(t,X);
title('absolute value with sign function');