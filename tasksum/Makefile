all: main.o my_sum.o
	g++ -o tasksum main.o my_sum.o

main.o: main.cpp
	g++ -c main.cpp

my_sum.o: my_sum.cpp my_sum.h
	g++ -c my_sum.cpp 