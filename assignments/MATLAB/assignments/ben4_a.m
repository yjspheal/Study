syms x n k
f(x)=(sin(x))/(2-cos(x));
df(x)=diff(f(x),'x');
d2f(x)=diff(df(x),'x');
solve(df(x))
solve(d2f(x))
hold on
fplot(x,f(x),'b')
plot(-pi/3,f(-pi/3),'marker','x')
plot(pi/3,f(pi/3),'marker','x')
plot(0,f(0),'marker','o')
hold off