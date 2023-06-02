all: Graph

Graph: graph.o calculate.o stack.o draw.o polish_notation.o
	gcc -o ../build/Graph *.o	

graph.o: graph.c
	gcc -c -Wall -Werror -Wextra graph.c

calculate.o : calculate.c
	gcc -c -Wall -Werror -Wextra calculate.c

stack.o: stack.c
	gcc -c -Wall -Werror -Wextra stack.c

draw.o: draw.c
	gcc -c -Wall -Werror -Wextra draw.c

polish_notation.o : polish_notation.c
	gcc -c -Wall -Werror -Wextra polish_notation.c

clean:
	rm -rf *.o ../build/Graph

rebuild: clean all