syms x 
f(x) = 1/(1+exp(x)); 
xMin = 0; xMax = 5; 
n = 40; 
dx = (xMax-xMin)/n; 
SimpsonSum = 0; 
xValues = xMin : 2*dx : (xMax - 2*dx); 
for i = 1 : length(xValues)    
    v = xValues(i);    
    SimpsonSum = SimpsonSum + (1/3*f(v) + 4/3*f(v+dx) +1/3*f(v+2*dx))*dx; 
end
double(SimpsonSum)
double(int(f(x),'x',0,5))