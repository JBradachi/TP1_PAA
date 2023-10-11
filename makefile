all: 
	clear
	gcc ./headers/TadMapa.h	 TadMapa.c  main.c	TadBT.c ./headers/TadBT.h  -o	 exec
	./exec 
clean:
	rm -rf *.o ./exec
	clear