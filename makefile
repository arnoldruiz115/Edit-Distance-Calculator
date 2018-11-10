main: main.o
	g++ main.o -o EditDist

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm -f EditDist main.o
