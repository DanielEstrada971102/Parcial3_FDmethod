CC := g++
INC_DIR := include
SRC_DIR := src

OBJ1 := $(SRC_DIR)/fd_method.cpp main.cpp
OBJ2 := $(SRC_DIR)/fd_method.cpp prueba_funcionesPQR/prueba.cpp
OBJ3 := $(SRC_DIR)/fd_method.cpp prueba_matriz/prueba.cpp
OBJ4 := $(SRC_DIR)/fd_method.cpp convergencia/convergencia_test.cpp

CFLAGS   := -Iinclude -Wall 

$(EXEC) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(EXEC)


functions_test: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o function_test.out


matriz_test: $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o matriz_test.out


convergencia_test: $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o convergencia_test.out

clean:
	rm *.out *.txt convergencia/archivos/*.txt convergencia/graficas/*.png