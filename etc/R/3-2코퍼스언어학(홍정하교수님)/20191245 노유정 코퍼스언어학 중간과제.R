#1번 코드
TEXT1 <- scan(file = "Q1/Q1_01.txt", what = "", quote = NULL)
TEXT2 <- scan(file = "Q1/Q1_02.txt", what = "", quote = NULL)
TEXT1 <- gsub("^[[:punct:]]+|[[:punct:]]+$", "" ,tolower(TEXT1))
TEXT1 <- sort(TEXT1)
Freq.T1 <- table(TEXT1)[names(table(TEXT1)) %in% intersect(TEXT1,TEXT2)]
Freq.T1 <- data.frame(Freq.T1)
colnames(Freq.T1) <- c("어휘","빈도")
write.table(Freq.T1, file = "Q1_out1.txt",sep = "\t", quote = F, col.names = NA)



#2번 코드
dir.create("./Q2_out")
for (f_n in list.files(path='./Q2', pattern='[.]txt$'))
{
TEXT <- vector()
file <- scan(file = paste('./Q2/',f_n, sep = ""), what = "", quote = NULL, sep = "\n", encoding = "UTF-8")
f_splt <- unlist(strsplit(file[grep("</?body>",file)[1]:grep("</?body>",file)[2]-1],"<|>"))
for (i in 1:length(f_splt))
{if (f_splt[i] == "/w" | f_splt[i] == "/c" | f_splt[i] == "/mw")
{TEXT <- c(TEXT, f_splt[i-1])}}
TEXT <- gsub(" ","",TEXT)
write(TEXT, file = paste("Q2_out/", toupper(gsub(".txt","",f_n)), ".txt", sep=""), sep="\n")
}