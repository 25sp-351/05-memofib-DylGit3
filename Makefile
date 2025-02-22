CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = fibonacci
OBJS = fibonacci.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

fibonacci.o: fibonacci.c
	$(CC) $(CFLAGS) -c fibonacci.c -o fibonacci.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
