CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = fibonacci
OBJS = fibonacci.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)

fibonacci.o: fibonacci.c fibonacci.h
	$(CC) $(CFLAGS) -c fibonacci.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
