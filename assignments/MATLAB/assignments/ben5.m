syms x
V(x)=(3-2*x)^(2)*x
dV(x)=diff(V(x),'x')
solve(dV(x))
double(V(1/2))