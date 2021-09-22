# COMPILER
CC = g++

# FLAGS
CPPFLAGS = -std=c++17 -ggdb3 -pipe -O2 -Wall -Werror

# PATHS:
TESTPATH0 = /home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/test-data-0.txt

# EXECUTABLE FILE NAME
EXENAME = output

all: input

input: maximum-pairwise-product
	./$(EXENAME) < $(TESTPATH0)

maximum-pairwise-product: maximum-pairwise-product.o test.o
	$(CC) $(CPPFLAGS) maximum-pairwise-product.o test.o -o $(EXENAME)

maximum-pairwise-product.o: maximum-pairwise-product.cpp
	$(CC) -c $(CPPFLAGS) maximum-pairwise-product.cpp

test.o:	test.cpp
	$(CC) -c $(CPPFLAGS) test.cpp

clean:
	rm -rf *o && rm -rf $(EXENAME)
