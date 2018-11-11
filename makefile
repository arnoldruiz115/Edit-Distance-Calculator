main: main.o distcalc.o
	g++ main.o distcalc.o -o EditDist

main.o: main.cpp
	g++ -c main.cpp

distcalc.o: distcalc.cpp distcalc.h
	g++ -c distcalc.cpp

clean:
	rm -f EditDist main.o distcalc.o
