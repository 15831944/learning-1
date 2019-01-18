function graphics2d()
    function histograms()
        figure(5);
        x=-3:.3:3;
        y=randn(10000,1);
        hist(y,x);
        figure(6);
        subplot(2,1,1);
        x=2*pi*rand(100,1);
        [t r]=rose(x,10);
        rose(x,10);
        hold on;
        subplot(2,1,2);
        polar(t,r);
        hold off;
    end
    function plots()
        figure(3);
        t=0:0.2:2*pi;
        f=sin(t);
        subplot(2,1,1);
        stem(t,f);
        hold on;
        grid;
        plot(t,f);
        stairs(t,f);
        hold off;
        subplot(2,1,2);
        hold on;
        plot(t,f);
        grid;
        bar(t,f);
        hold off;
        figure(4);
        x=0:.2:6;
        y=sin(x);
        e=rand(size(x))/5;
        errorbar(x,y,e);
    end
x1=[0 3 2 -1];
y1=[-1 -1 2 2];
x2=[3 5 2];
y2=[-1 3 2];
figure(1);
fill(x1,y1,'b',x2,y2,'g');
t=0:.01:2*pi;
f=sin(2*t).*cos(2*t);
figure(2);
polar(t,f);
%functions call
plots();
histograms()
%another plots
figure(7);
z=[2-5*i -2+i 3+2*i];
subplot(2,1,1);
compass(z);
grid;
hold on;
subplot(2,1,2);
feather(z);
grid;
hold off;
figure(8);
t=0:1/10000:.1;
y=sin(2*pi*50*t);
comet(t,y,.2);

end