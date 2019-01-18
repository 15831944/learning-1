function [f,X]=test4_1
% Acest program face fft


t=0:.001:.039;
fe=1/(t(2)-t(1))
x=2*sin(2*pi*50*t)+1.5*sin(2*pi*100*t)+sin(2*pi*200*t)+.5*sin(2*pi*350*t);
Xt=fft(x);
Xm=abs(Xt);
N=length(x);
X=Xm(1:N/2+1);
f=[0:N/2]*fe/N;
subplot(211);plot(t,x);
subplot(212);stem(f,X)