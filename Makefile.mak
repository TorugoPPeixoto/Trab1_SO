EXEC = main

CC = gcc
CFLAGS = -Wall -Wextra -pthread

SRC = main.c functions.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

rebuild: clean all
