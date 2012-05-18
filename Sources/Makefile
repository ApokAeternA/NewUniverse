NewUniverse : main.o core.o interface_SDL.o
	g++ -o NewUniverse main.o core.o interface_SDL.o -lSDL

main.o : main.cpp
	g++ -c main.cpp -lSDL

core.o : core.cpp core.h
	g++ -c core.cpp -lSDL

interface_SDL.o : interface_SDL.cpp interface_SDL.h
	g++ -c interface_SDL.cpp -lSDL

clean :
	rm -f *.o

