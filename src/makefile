CC = gcc

CFLAGS = -Wall -Werror -g

TARGET = my_program

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

# target build
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# object build rule from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
