CC = gcc
CFLAGS = -Wall
TARGET = permutations.exe
SRC = permutations.c
OBJ = permutations.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q *.o $(TARGET) 2>nul || echo Clean complete

