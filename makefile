check : main.cpp HashTable.cpp
	g++ -o check main.o HashTable.o

main.o : main.cpp
	g++ -c main.cpp

