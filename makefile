PROJ=biginteger_tester
PROTO=biginteger.cpp
CC=g++
CFLAGS=-std=c++11 -Wall

$(PROJ):	$(PROJ).cpp
	$(CC) $(CFLAGS) -o $@ $^ $(PROTO)

.PHONY:	clean

clean:	
	rm $(PROJ)
