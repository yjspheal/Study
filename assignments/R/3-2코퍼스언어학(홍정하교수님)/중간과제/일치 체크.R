i=1
for (f_n in list.files(path='./Q2_out'))
{
f1 <- scan(file = paste('./Q2/',f_n, sep = ""), what = "", quote = NULL)
f2 <- list.files(path='./Out2')[i]
f2 <- scan(file = paste('./Q2/',f2, sep = ""), what = "", quote = NULL)
if (paste(f1, collapse="") == paste(f2, collapse=""))
{print(TRUE)}
i <- i + 1
}