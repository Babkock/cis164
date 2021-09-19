OPTS = -Wall -O2

all: foodtruck

foodtruck: main.o menu.o purchase.o sales.o
	g++ main.o menu.o purchase.o sales.o -o foodtruck
	strip foodtruck

main.o: main.cpp
	g++ ${OPTS} -c main.cpp

menu.o: menu.cpp
	g++ ${OPTS} -c menu.cpp

purchase.o: purchase.cpp
	g++ ${OPTS} -c purchase.cpp

sales.o: sales.cpp
	g++ ${OPTS} -c sales.cpp

clean:
	rm foodtruck main.o menu.o purchase.o sales.o

