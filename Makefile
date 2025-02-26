CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = fibonacci
OBJS = fibonacci.o cache.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)

fibonacci.o: fibonacci.c fibonacci.h cache.h
	$(CC) $(CFLAGS) -c fibonacci.c

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
