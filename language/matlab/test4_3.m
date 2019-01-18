function  [f,X]=test4_3
% This program does the spectral analysis
% of a signal X with thre components.
t=0:.001:.099;
fe=1000;
x=4*sin(2*pi*50*t)+2*sin(2*pi*100*t)+6*sin(2*pi*350*t);
Xt=fft(x);
N=length(x);
Xm=abs(Xt);
X=Xm(1,1:N/2+1)/(N/2);
f=[0:N/2]*fe/N;
subplot(211);
plot(t,x);
grid;
xlabel('t[s]');
ylabel('x(t)[V]');
title('Temporal signal');
subplot(212);
stem(f,X);
xlabel('f[Hz]');
ylabel('X(f)[V]');
grid;
title('Spectral analysis of a signal');