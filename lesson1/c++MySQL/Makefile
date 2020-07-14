SRC=test.cpp
DES=test 
CC=g++
FLAG=-std=c++11 -lpthread -L/usr/lib64/mysql -lmysqlclient 

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

.PHONY:clean 
clean:
	rm $(DES)

