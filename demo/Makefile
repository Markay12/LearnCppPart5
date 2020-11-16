recTest: main.o  shape.o
	g++ -g -Wall main.o shape.o -o recTest

main.o: main.cpp shape.h
	g++ -g -Wall main.cpp -c

shape.o: shape.h
	g++ -g -Wall shape.cpp -c
