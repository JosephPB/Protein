protein: protein.o functions.o
	g++ -std=c++11 -o protein protein.o functions.o

protein.o: protein.cpp functions.h
	g++ -std=c++11 -c protein.cpp

functions.o: functions.cpp functions.h
	g++ -std=c++11 -c functions.cpp

clean :
	rm protein protein.o functions.o
