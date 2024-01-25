OBJECT=main.o read.o write.o
GC=gcc -c

compile:$(OBJECT)
	gcc -o compile  main.o read.o write.o

main.o:main.c
	$(GC) main.c
read.o:read.c
	$(GC) read.c
write.o:write.c
	$(GC) write.c

