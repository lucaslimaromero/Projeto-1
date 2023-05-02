APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps

libed:
	gcc -c $(SRC)/lista.c -I $(INCLUDE) -o $(OBJ)/lista.o

myapps:
	gcc $(APPS)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main

run:
	$(BIN)/main

clear:
	rm $(BIN)/* $(OBJ)/*