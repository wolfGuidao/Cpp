SRC=main.cpp Redis.cpp 
DES=test 
CC=g++
FLAG=-std=c++11 -lpthread -L/usr/lib64/mysql -lmysqlclient -L/usr/local/lib -lhiredis

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

.PHONY:clean 
clean:
	rm $(DES)

