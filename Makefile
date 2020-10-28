CC := g++
INC_DIR := include
SRC_DIR := src

OBJ1 := $(SRC_DIR)/fd_method.cpp main.cpp
OBJ2 := $(SRC_DIR)/fd_method.cpp prueba_funcionesPQR/prueba.cpp
OBJ3 := $(SRC_DIR)/fd_method.cpp prueba_matriz/prueba.cpp

CFLAGS   := -Iinclude -Wall 
EXEC := a.out

$(EXEC) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(EXEC)


function_test: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(EXEC)


matriz_test: $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(EXEC)


clean:
	rm *.out *.txt