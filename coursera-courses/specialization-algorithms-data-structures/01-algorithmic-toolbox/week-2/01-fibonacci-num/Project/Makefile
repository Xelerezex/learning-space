# COMPILER
CC = g++

# FLAGS
CPPFLAGS = -std=c++17 -ggdb3 -pipe -O2 -Wall -Werror

# EXECUTABLE FILE NAME
EXENAME = output

all: input

input: 01-fibonacci
	./$(EXENAME)

01-fibonacci: 01-fibonacci.o
	$(CC) $(CPPFLAGS) 01-fibonacci.o -o $(EXENAME)

01-fibonacci.o: 01-fibonacci.cpp
	$(CC) -c $(CPPFLAGS) 01-fibonacci.cpp

clean:
	rm -rf *o && rm -rf $(EXENAME)
