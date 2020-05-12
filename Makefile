CC = gcc
OBJ = main

all:
	$(CC) game.c main.c -o $(OBJ)

exec:
	./$(OBJ)

doc:
	doxygen dconfig
	$(MAKE) -C docs/latex
	xdg-open docs/html/index.html
	xdg-open docs/latex/refman.pdf

dist:
	mkdir Game_of_Life && cp game.c main.c game.h Makefile Game_of_Life && tar -czvf Game_of_Life.tar.gz Game_of_Life && rm -rf Game_of_Life

clean:
	rm -rf $(OBJ)
