CFLAGS = -Wall -Wextra -Werror -Wpedantic -g -std=c11
CC = clang

EXECUTABLE = businessdb
SOURCES = main.c hashtable.c fileio.c utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

test:
	./tests
