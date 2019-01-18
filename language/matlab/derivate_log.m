function [d1f,d2f]=derivate_log()
x=50:2:58;
h=x(2)-x(1);
y=log10(x);
d1y=diff(y);
d2y=diff(d1y);
d3y=diff(d2y);
d4y=diff(d3y);
d1f=(1/h)*(d1y(1)-d2y(1)/2+d3y(1)/3-d4y(1)/4);
d2f=(1/h^2)*(d2y(1)-d3y(1)+(11/12)*d4y(1));