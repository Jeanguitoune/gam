all: gam

gam: main.o
	gcc -o gam main.o 

main.o: main.c
	gcc -c main.c 

clean:
	rm *.o
