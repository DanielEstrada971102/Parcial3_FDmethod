CC := g++
CFLAGS   := -Iinclude -Wall 
OBJ := fd_method.o main.o
EXEC := a.out

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
	rm $(OBJ)

clean:
	rm *.o