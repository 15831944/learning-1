function [m,n]=lms()
x=[0 1 2 3 4 5];
y=[0 20 60 68 77 110];
coef=polyfit(x,y,1);
m=coef(1);
n=coef(2);
y1=m*x+n;
sum_p=sum((y-y1).^2);
axis([-1 6  -20 120]);
plot(x,y1,x,y,'o');
grid;