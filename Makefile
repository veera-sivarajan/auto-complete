CC = gcc
CFLAGS = -g -Wall -std=c99
OBJECTS = $(filter-out test.c, $(wildcard *.c)) #Source files
NAME = autoC #Desired filename
TODELETE = *.o # the *.o should be the same as the objects
LIBS = -lreadline

mt-collatz : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBS) 

.PHONY: clean run

clean:
	rm -f $(TODELETE)

run:	autoC
	./autoC
