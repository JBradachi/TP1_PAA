all: 
	clear
	gcc ./headers/TadMapa.h	 TadMapa.c  main.c	 -o	 exec
	./exec 
clean:
	rm -rf *.o ./exec
	clear