# Compiler settings - Can be customized.
CC = gcc
CFLAGS = -Wall -g

# Define the output executable name
TARGET = main

# Makefile variables for file management.
SRCS = main.c singlylinkedlist.c
OBJS = $(SRCS:.c=.o)
EXEC = main

# Default target: build the executable
all: $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Link the target with all the object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file to an object file
main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

singlylinkedlist.o: singlylinkedlist.c main.h
	$(CC) $(CFLAGS) -c singlylinkedlist.c

# Clean target to remove object files and the executable
# 'make clean' will run this
clean:
	rm -f $(TARGET) $(OBJS)

# This is a typical make target for .PHONY which lists targets that are not actual files
.PHONY: clean