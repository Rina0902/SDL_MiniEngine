prog: func.o main.o
	gcc func.o main.o -o prog -g -LSDL -LSDL_image -lSDL_mixer
main.o: main.c
	gcc -c main.c -g -LSDL -LSDL_image 
func.o: func.c
	gcc -c func.c -g -LSDL -LSDL_image
