def fibo(n):
    i=0
    F=[0,1]
    while i in range(0,n-1):
        F.append(F[i]+F[i+1])
        i+=1
    return F[n]

