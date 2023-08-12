%Simpson's Method
syms x
f(x)=exp(x);
xMin = 1; xMax = 3; n=30*2;
dx=(xMax-xMin)/n;
SSSum=0;
xValues=xMin : 2*dx : xMax-2*dx;
hold on
for i = 1 : length(xValues)
    v=xValues(i);
    SSSum=SSSum+(1/3*f(v)+4/3*f(v+dx)+1/3*f(v+2*dx))*dx;
end
hold off
double(SSSum)
    