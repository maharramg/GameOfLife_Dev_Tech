CC = gcc
OBJ = main

all:
	$(CC) game.c main.c -o $(OBJ)

exec:
	./$(OBJ)

doc:
	mkdir documentation
	@echo "Documentation folder created."

dist:
	mkdir game && cp game.c main.c includes.h game && tar -czvf game.tar.gz game && rm -rf game

clean:
	rm -rf $(OBJ)