protein: protein.o functions.o
	g++ -o protein protein.o functions.o

protein.o : protein.cpp
	g++ -c protein.cpp

functions.o : functions.cpp
	g++ -c functions.cpp

clean :
	rm protein protein.o functions.o
