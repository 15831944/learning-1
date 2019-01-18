function specfunc()
x=0:.25:20;
niu=[0 1 2];
figure(1);
for i=1:3
    J=besselj(niu(i),x);
    plot(x,J); hold on;
    grid;
end
hold off;
x=0:.1:2;
niu=[0 1 2];
figure(2);
for i=1:3
    N=besseli(niu(i),x);
    plot(x,N);hold on;
    grid;
end
hold off;
%Laplace (GAUSS)
z=-4:.01:4;
f=1./(sqrt(2*pi))*exp(-z.^2/2);
figure(3);
plot(z,f);grid;
