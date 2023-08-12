TEXT1 <- scan(file="Q1/Q1_01.txt", what="", quote=NULL)
TEXT2 <- scan(file="Q1/Q1_02.txt", what="", quote=NULL)
TEXT1 <- gsub("^[[:punct:]]+|[[:punct:]]+$", "" ,tolower(TEXT1))
TEXT1 <- sort(TEXT1)
Freq.T1 <- table(TEXT1)[names(table(TEXT1)) %in% intersect(TEXT1,TEXT2)]
Freq.T1 <- data.frame(Freq.T1)
colnames(Freq.T1) <- c("พ๎ศึ","บคลอ")
write.table(Freq.T1, file = "Q1_out1.txt",sep="\t", quote=F, col.names=NA)