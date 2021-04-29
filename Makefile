
output: projeto.o
	g++ projeto.o -o output

projeto.o: projeto.c projeto.h
	g++ -c projeto.c

clean:
	rm *.o output