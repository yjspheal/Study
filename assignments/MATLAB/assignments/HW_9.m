%% ø¿¿œ∑Ø
syms x
tl=0;
tF=3;
dt=pi/8;
flnitialValue=1;

times=tl:dt:tF;

fEuler3(1)=flnitialValue;
for i = 1:length(times)-1
    dfdt(i)= sin(times(i));
    d2fdt2(i)=cos(times(i));
    d3fdt3(i)=-sin(times(i));
    fEuler3(i+1)=fEuler3(i)+dfdt(i)*dt+1/2*d2fdt2(i)*dt^2+1/6*d3fdt3(i)*dt^3;
end

fEuler2(1)=flnitialValue;
for i = 1:length(times)-1
    dfdt(i)= sin(times(i));
    d2fdt2(i)=cos(times(i));
    fEuler2(i+1)=fEuler2(i)+dfdt(i)*dt+1/2*d2fdt2(i)*dt^2;
end

fEuler1(1)=flnitialValue;
for i = 1:length(times)-1
    dfdt(i)=sin(times(i));
    fEuler1(i+1)=fEuler1(i)+dfdt(i)*dt;
end
fEuler2(length(fEuler2))
fEuler1(end)
g(x)=2-cos(x);
hold on
fplot(g(x),[0,pi],'color','k')
plot(times, fEuler3,'y')
plot(times, fEuler2,'r')
plot(times,fEuler1,'b')
hold off