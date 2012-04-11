l: gam

gam: main.o
	gcc -o gam main.o 

main.o: src/main.c
	gcc -c src/main.c 

clean:
	rm *.o
	rm gam
