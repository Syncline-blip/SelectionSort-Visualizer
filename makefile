CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -std=c89
OBJ = main.o newSleep.o randArray.o LinkedList.o fileIO.o sorting.o
TARGET = main
.PHONY: all test clean

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o : main.c
	$(CC) $(CFLAGS) main.c -c

newSleep.o : newSleep.c
	$(CC) $(CFLAGS) newSleep.c -c

randArray.o : randArray.c
	$(CC) $(CFLAGS) randArray.c -c

LinkedList.o : LinkedList.c
	$(CC) $(CFLAGS) LinkedList.c -c

fileIO.o : fileIO.c
	$(CC) $(CFLAGS) fileIO.c -c

sorting.o : sorting.c
	$(CC) $(CFLAGS) sorting.c -c

clean:
	rm -f $(TARGET) $(OBJ)
	
