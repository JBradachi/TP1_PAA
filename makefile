all: 
	clear
	gcc ./headers/TadMapa.h	 ./sources/TadMapa.c  mainTeste.c	./sources/TadBT.c ./headers/TadBT.h  -o	 exec
	./exec 
clean:
	rm -rf *.o ./exec
	clear