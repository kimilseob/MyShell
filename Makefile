myshell : function.o myshell.o
	gcc -o myshell function.o myshell.o

function.o : function.c
	gcc -c -o function.o function.c

myshell.o : myshell.c
	gcc -c -o myshell.o myshell.c

clean : 
	rm *.o myshell
