function compinterp(x,y,xi)
%yi=spline(x,y,xi);
yi=interp1(x,y,xi,'spline');
zi=interp1(x,y,xi,'cubic');
axis([min(x)-1 max(x)+1 min(y)-1 max(y)+1]);
plot(x,y,xi,yi,xi,zi,x,y,'o');
title('Interpolare liniara, spline si cubica');
