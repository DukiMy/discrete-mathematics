CC = gcc
CFLAGS = -Wall
TARGET = charIO

all: $(TARGET)

$(TARGET): charIO.o
	gcc $(CFLAGS) -o $(TARGET) charIO.o

charIO.o: charIO.c
	gcc $(CFLAGS) -c charIO.c

clean:
	del /Q *.o $(TARGET).exe 2>nul || echo Clean complete

