syms x
f(x) =(x^2+1);
xMin = 0; xMax = 3;
n=40;
dx=(xMax-xMin)/n;
RightRiemannSum = 0;
xValues = (xMin+dx) : dx : (xMax);
hold on
for i = 1:length(xValues)
    v=xValues(i);
    fill([v,v,v-dx,v-dx], [0,f(v),f(v),0],'cyan');
    
    RightRiemannSum = RightRiemannSum + f(v)*dx;
end
fplot(f(x),[xMin,xMax])
hold off
double(RightRiemannSum)