#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/intro

__start__: ./intro
	./intro

./intro: obj obj/main.o obj/introspec.o 
                        
	g++ -Wall -pedantic -std=c++11 -o ./intro obj/main.o obj/introspec.o 

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/introspec.hh 
        
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/introspec.o: inc/introspec.hh src/introspec.cpp
	g++ -c ${CXXFLAGS} -o obj/introspec.o src/introspec.cpp

clean:
	rm -f obj/*.o ./intro