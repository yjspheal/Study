%the trapezoid Method
syms x
f(x)=x^2*log(x);
xMin=1; xMax=3;
n=30;
dx = (xMax - xMin)/n;
trapezoidSum=0;
hold on
xValues=xMin:dx:(xMax-dx);
f(xValues);
for i = 1:length(xValues)
    v=xValues(i);
    fill([v,v,v+dx,v+dx],[0,f(v),f(v+dx),0],'cyan')
    trapezoidSum=trapezoidSum+((f(v)+f(v+dx))*dx/2);
end
fplot(f(x),[xMin,xMax])
hold off
double(trapezoidSum)




