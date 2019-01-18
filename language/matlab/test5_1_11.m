function sum=test5_1_11(x,val)
%this is the example 5.1.11 from MATLAB book
%this computes the sum the x vector until it reaches the value val
sum=0;
final=length(x);
%i=1;
%while (x(i)<val) & (i<=final)
%    sum=sum+x(i);
%    i=i+1;
%end
for i=1:final
    if x(i)>=val
        break;
    end
    sum=sum+x(i);
end