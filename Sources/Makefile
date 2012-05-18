NewUniverse : main.o core.o
	g++ -o NewUniverse main.o core.o

main.o : main.cpp
	g++ -c main.cpp

core.o : core.cpp core.h
	g++ -c core.cpp

clean :
	rm -f *.o

