# COMPILER
CC = g++

# FLAGS
CPPFLAGS = -std=c++17 -ggdb3 -pipe -O2 -Wall -Werror

# COMPILED FILE NAME
CMPFILENAME = 04-lcm

# EXECUTABLE FILE NAME
EXENAME = output

all: input

input: $(CMPFILENAME)
	./$(EXENAME)

$(CMPFILENAME): $(CMPFILENAME).o
	$(CC) $(CPPFLAGS) $(CMPFILENAME).o -o $(EXENAME)

$(CMPFILENAME).o: $(CMPFILENAME).cpp
	$(CC) -c $(CPPFLAGS) $(CMPFILENAME).cpp

clean:
	rm -rf *o && rm -rf $(EXENAME)
