function test5_1_8
%example 5.1.8 from MATLAB book
x=-10:20;
for k=1:length(x)
    if x(k)<=2
        f(k)=2*x(k)+3;
    else
        f(k)=2*x(k)^2-1;
    end
end
plot(x,f);
        