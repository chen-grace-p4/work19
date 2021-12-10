all: userint.o worker.o
	gcc -o userint userint.o
	gcc -o worker worker.o

userint.o: userint.c
	gcc -c userint.c

worker.o: worker.c
	gcc -c worker.c

clean:
	rm *.o
	rm userint
	rm worker
