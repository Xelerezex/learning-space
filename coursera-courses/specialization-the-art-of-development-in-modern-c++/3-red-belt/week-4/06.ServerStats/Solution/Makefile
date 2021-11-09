CC = clang++
CFLAGS = -std=c++17 -ggdb3 -pipe -O2 -Wall -Werror

all : execute

execute : output
	./output

output : stats.o server_stats.o
	$(CC) $(CFLAGS) stats.o server_stats.o -o output

# Main
server_stats.o: server_stats.cpp stats.h http_request.h
	$(CC) -c $(CFLAGS) server_stats.cpp

stats.o: stats.cpp stats.h http_request.h test_runner.h profile.h
	$(CC) -c  $(CFLAGS) stats.cpp


clear :
	rm -rf *o && rm -rf output
