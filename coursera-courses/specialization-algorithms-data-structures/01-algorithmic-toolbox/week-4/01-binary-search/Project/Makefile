# COMPILER
CC = clang++

# FLAGS
CPPFLAGS = -std=c++17 -ggdb3 -pipe -O2 -Wall -Werror

# COMPILED FILE NAME
CMPFILENAME = 01-binary-search

CMPTESTRUNH = test_runner
CMPPROFILEH = profile
RANDOM      = random_generate


# EXECUTABLE FILE NAME
EXENAME = output

all: input

input: $(CMPFILENAME)
	./$(EXENAME)

$(CMPFILENAME): $(CMPFILENAME).o
	$(CC) $(CPPFLAGS) $(CMPFILENAME).o -o $(EXENAME)

# PATTERN: file.o: file.cpp  file.h other_header.h
$(CMPFILENAME).o: $(CMPFILENAME).cpp $(CMPTESTRUNH).h $(CMPPROFILEH).h $(RANDOM).h
	$(CC) -c $(CPPFLAGS) $(CMPFILENAME).cpp

clear:
	rm -rf *o && rm -rf $(EXENAME)
