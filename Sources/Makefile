clean : SakuraTree-RPG 
	rm -f *.o

SakuraTree-RPG : main.o core.o
	g++ -o SakuraTree-RPG main.o core.o

main.o :
	g++ -c main.cpp

core.o : core.h
	g++ -c core.cpp

