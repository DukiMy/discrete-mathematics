CC = gcc
CFLAGS = -Wall
FASTFLAGS = -O3 -Wall

TARGET = permutations.exe
FASTTARGET = fast_ros.exe

SRC = permutations.c
OBJ = permutations.o

all: $(TARGET) $(FASTTARGET)

# Standard build
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Optimized build
$(FASTTARGET): $(SRC)
	$(CC) $(FASTFLAGS) -o $@ $<

# Compile object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q *.o *.exe 2>nul || echo Clean complete
