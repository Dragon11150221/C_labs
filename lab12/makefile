all: sorting grading

sorting: l12.o tool.o
	gcc -Wall -std=c99 l12.o tool.o -o sorting
grading: l12.o tool.o
	gcc -Wall -std=c99 l12.o tool.o -o grading
l12.o: l12.c l12.h tool.h
	gcc -Wall -std=c99 -c l12.c
tool.o: tool.c tool.h
	gcc -Wall -std=c99 -c tool.c

tar:
	tar -cvf submit.tar *.c *.h makefile *.txt

.PHONY : clean
clean :
	rm *.o sorting grading
