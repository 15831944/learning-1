function graphics3d()
    function contour2d()
        [x y]=meshgrid(-2:.2:2, -2:.2:3);
        z=x.*exp(-x.^2-y.^2);
        figure;
        subplot(2,1,1);
        contour(-2:.2:2,-2:.2:3,z,8);
        subplot(2,1,2);
        C=contour(-2:.2:2,-2:.2:3,z,8);
        clabel(C);
    end
    function contour3d()
        x=-3:.125:3;
        [X Y]=meshgrid(x,x);
        Z=peaks(X,Y);
        figure;
        subplot(2,1,1);
        contour3(X,Y,Z,20);
        subplot(2,1,2);
        mesh(X,Y,Z);
    end
    function vectors()
        dom=-2:.5:2;
        dx=rand(length(dom),length(dom))-0.5;
        dy=rand(length(dom),length(dom))-0.5;
        figure;
        quiver(dom,dom,dx,dy);
    end
    function spiral3d()
        figure;
        subplot(2,1,1);
        t=0:pi/50:10*pi;
        plot3(sin(t),cos(t),t);
        subplot(2,1,2);
        comet3(sin(t),cos(t),t);
    end
    function surfaces()
        figure;
        [x y]=meshgrid(-2:.2:2,-2:.2:2);
        z=x.*exp(-x.^2-y.^2);
        subplot(3,2,1);
        mesh(x,y,z);
        subplot(3,2,2);
        meshc(x,y,z);
        subplot(3,2,3);
        meshz(x,y,z);
        subplot(3,2,4);
        surf(x,y,z);
        subplot(3,2,5);
        surfc(x,y,z);
    end
    function objects()
        figure;
        subplot(2,2,1);
        Rc1=0.5;
        Rc2=0;
        Hc=7.5;
        N=30;
        [xc yc zc]=cylinder([Rc1 Rc2],N);
        zc=zc*Hc;
        view([-37.5 30]);
        surface(xc,yc,zc);
        grid;
        subplot(2,2,2);
        Rp1=1;
        Rp2=0.5;
        Hp=7.5;
        N=6;
        [xp yp zp]=cylinder([Rp1 Rp2],N);
        zp=zp*Hp;
        view([-37.5 30]);
        surface(xp,yp,zp);
        grid;
        subplot(2,2,3);
        [x y z]=sphere(20);
        mesh(x,y,z);
        grid;
    end
%contour2d();
%contour3d();
%vectors();
%spiral3d();
surfaces();
objects();
end