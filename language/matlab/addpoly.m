function z=addpoly(x,y)
tempsize=size(x);
szx=tempsize(2);
tempsize=size(y);
szy=tempsize(2);
x1=zeros(1);
y1=zeros(1);
if szx<szy
    x1=zeros(1,szy);
    low=szy-szx+1;
    x1(low:szy)=x;
    y1=y;
else if szy<szx
    y1=zeros(1,szx);
    low=szx-szy+1;
    y1(low:szx)=y;
    x1=x;
    else
        x1=x;
        y1=y;
    end;
end;
z=x1+y1;