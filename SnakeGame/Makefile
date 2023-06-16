objects=main.o snake.o boundary.o food.o load.o welcome.o

exe: $(objects)
	gcc $(objects) -o exe

main.o: controls.h

snake.o food.o: snake.h

boundary.o: boundary.c
	gcc -c boundary.c

load.o: load.c
	gcc -c load.c

welcome.o: welcome.c
	gcc -c welcome.c

.PHONY: clean

clean:
	-rm $(objects) exe
