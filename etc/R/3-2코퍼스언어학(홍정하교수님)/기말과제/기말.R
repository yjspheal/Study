UN18 <- scan(file="BTS_UN2018.txt", what="", quote=NULL, encoding="UTF-8")
UN18 <- gsub('^[[:punct:]]*|[[:punct:]]$','',tolower(UN18))
UN18.table <- sort(table(UN18),decreasing=T)
UN18.Freq <- data.frame(UN18.table)
head(UN18.Freq,15)

UN20 <- scan(file="BTS_UN2020.txt", what="", quote=NULL, encoding="UTF-8")
UN20 <- gsub('^[[:punct:]]*|[[:punct:]]$','',tolower(UN20))
UN20.table <- sort(table(UN20),decreasing=T)
UN20.Freq <- data.frame(UN20.table)
head(UN20.Freq,15)



for i in list.files(path = "./", pattern='[.]txt$')
{
