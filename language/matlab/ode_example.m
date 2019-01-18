function ode_example()
    function dy=g1(x,y)
        dy=3*x^2;
    end
    function dy=g2(x,y)
        dy=-0.1*y;
    end
    function dy=g3(x,y)
        dy=3*y+exp(2*x);
    end
figure(1);
[x yn]=ode23(@g1,[2 4],0.5);
ya=x.^3-7.5;
plot(x,yn,'o',x,ya);grid;
figure(2);
[x yn]=ode23(@g2,[0 5],4);
ya=4.*exp(-0.1.*x);
plot(x,yn,'o',x,ya);grid;
figure(3);
[x yn]=ode23(@g3,[0 2],3);
ya=4*exp(3.*x)-exp(2.*x);
plot(x,yn,'o',x,ya);grid;
end