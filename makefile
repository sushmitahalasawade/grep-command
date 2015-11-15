project: main.o f.o
	cc main.o f.o -o project
main.o: main.c 
	cc  -c main.c
f.o: f.c 
	cc  -c f.c

