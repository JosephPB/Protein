protein: protein.o functions.o
	g++ -o protein protein.o functions.o

protein.o : protein.cpp functions.h
	g++ -c protein.cpp

functions.o : functions.cpp functions.h
	g++ -c functions.cpp

clean :
	rm protein protein.o functions.o
