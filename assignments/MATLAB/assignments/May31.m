syms x 
f(x)=exp(x);
xMin=0; xMax=1;
n=30;
dx = (xMax - xMin)/n;
trapezoidSum=0;
xValues=xMin:dx:(xMax-dx);
i = 1:length(xValues)
k=((f(xValues)+f(xValues+dx))*dx/2)
symsum(k(x),x,1,inf)
  %%
  syms x dx
f(x) = exp(x);
d(x)=limit(Df(x,dx),'dx',0);
fplot(x,d(x),[-2,2],'color','r')





































