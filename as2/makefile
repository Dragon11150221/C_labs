a2: main.o utility.o subset.o subset_m.o
	gcc -Wall -std=c99 main.o utility.o subset.o subset_m.o -o a2
main.o: main.c main.h utility.h subset.h subset_m.h
	gcc -Wall -std=c99 -c main.c
utility.o: utility.c utility.h
	gcc -Wall -std=c99 -c utility.c
subset.o: subset.c subset.h
	gcc -Wall -std=c99 -c subset.c
subset_m.o: subset_m.c subset_m.h
	gcc -Wall -std=c99 -c subset_m.c
