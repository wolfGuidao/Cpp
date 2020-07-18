SRC=main.cpp
DES=test 
CC=g++
FLAG=-std=c++11 -lpthread -ljsoncpp -L/usr/include/jsoncpp/json

SRC1=
DES1=

.PHONY:
all:$(DES) $(DES1)

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

$(DES1):$(SRC1)
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm -rf $(DES) $(DES1)
