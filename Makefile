OBJS=PDBP/pdbp.cpp main.cpp

CC=g++

COMPILER_FLAGS=-std=c++11 -w

LINKER_FLAGS=-lSDL2

OBJ_NAME=output

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

remove:
	rm $(OBJ_NAME)

run:
	./$(OBJ_NAME)

and-run:
	make
	make run
