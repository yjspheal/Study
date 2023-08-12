TEXT1 <- scan(file="Q1_01.txt", what="", quote=NULL)
TEXT2 <- scan(file="Q1_02.txt", what="", quote=NULL)
TEXT1 <- gsub("[[:punct:]]","",TEXT1)
TEXT2 <- gsub("[[:punct:]]","",TEXT2)
TEXT1 <- tolower(TEXT1)
TEXT2 <- tolower(TEXT2)
s=sort(intersect(TEXT1,TEXT2))
Freq1.table <- table(TEXT1)
Freq2.table <- table(TEXT2)
Freq11<-vector()
for( i in s)
{
Freq11<-c(Freq11,unname(Freq1.table[names(Freq1.table)==i]))
}
Freq21<-vector()
for( i in s)
{
Freq21<-c(Freq21,unname(Freq2.table[names(Freq2.table)==i]))
}
Freq.Data<-data.frame(row.names=s,Q1_01.txt=Freq11,Q1_02.txt=Freq21)
write.table(Freq.Data,file="out1.txt",quote=F,sep="\t",col.names=NA)




dir.create("./Q2_out")
for(i in list.files(path='./Q2'))
{
TEXT<-scan(file=paste0("./Q2/",i), what="char", quote=NULL
		,sep="\n", encoding="UTF-8")
write.table(TEXT,file=paste0("./Q2_out/",
			gsub("[:lower:]","[:upper:]",i)),
		quote=F, sep="\t")
}




dir.create("./Q3_out")
TEXT <- scan(file = paste0("./Q3/","Q3.txt"), what= "char", quote=NULL)
HM<-names(table(TEXT[grepl('.+[:]$',TEXT)]))
paragraph<-unlist(strsplit(paste(TEXT,collapse=' '),HM))
A<-vector(); B<-vector(); C<-vector(); D<-vector()
a=1
ALP=vector()
for(i in TEXT) { 
if(i==HM) { 
ALP=c(ALP,a) }
a=a+1 }
b=1
for(i in ALP){
if(TEXT[i]==HM[1])
{
A<-c(A,paste(TEXT[i],paragraph[b]))
}
else if(TEXT[i]==HM[2])
{
B<-c(B,paste(TEXT[i],paragraph[b]))
}
else if(TEXT[i]==HM[3])
{
C<-c(C,paste(TEXT[i],paragraph[b]))
}
else
{
D<-c(D,paste(TEXT[i],paragraph[b]))
}
b=b+1}
M=c(A,B,C,D)
for(i in 1:4)
{
write.table(M[i],file=paste0("./Q3_out/",
		gsub('[:]','',HM[i]),'.txt')
		,quote=F, sep="\t",col.names=NA)
}