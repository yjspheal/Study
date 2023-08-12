clc; clear;
syms x k n
f(x)=(1/factorial(k))*x^(k);
S(x)=symsum(f(x),k,2,inf)
S4(x)=symsum(f(x),k,2,4)
S7(x)=symsum(f(x),k,2,7)
S10(x)=symsum(f(x),k,2,10)
S(x)
hold on
fplot(S4(x),[-2,2],'k')
fplot(S7(x),[-2,2],'b')
fplot(S10(x),[-2,2],'r')
fplot(S(x),[-2,2],'y')
hold off
N=1;
