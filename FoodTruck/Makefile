OPTS = -Wall -O2

all: foodtruck

foodtruck: main.o menu.o sell.o
	g++ main.o menu.o sell.o -o foodtruck
	strip foodtruck

main.o: main.cpp
	g++ ${OPTS} -c main.cpp

menu.o: menu.cpp
	g++ ${OPTS} -c menu.cpp

sell.o: sell.cpp
	g++ ${OPTS} -c sell.cpp

clean:
	rm foodtruck main.o menu.o sell.o
