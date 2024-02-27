#
#
OBJECT=main.o read.o write.o
GC=gcc -c
INCLUDE=cmhead.h stdio.h string.h stdlib
all:test1.o app.o regis.o 
	gcc -o output    test1.o app.o regis.o  
test1.o:test1.c  
	$(GC) test1.c 
app.o:app.c  
	$(GC) app.c 
regis.o:app.c  	
	$(GC) regis.c 
