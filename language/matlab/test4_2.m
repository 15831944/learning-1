function [t,x]=test4_2
% Acest fisier reprezinta un semnal discret.
t=0:0.001:.059;
x=sin(2*pi*100*t)
stem(t,x)