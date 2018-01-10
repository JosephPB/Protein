protein: protein.o functions.o miyazawa_array.o
	g++ -std=c++11 -o protein protein.o functions.o miyazawa_array.o

protein.o: protein.cpp functions.h
	g++ -std=c++11 -c protein.cpp

functions.o: functions.cpp functions.h
	g++ -std=c++11 -c functions.cpp

miyazawa_array.o: miyazawa_array.cpp functions.h
	g++ -std=c++11 -c miyazawa_array.cpp

clean :
	rm protein protein.o functions.o miyazawa_array.o
