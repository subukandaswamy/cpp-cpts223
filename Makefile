all: clean compile execute

compile: setsmaps.cpp
	g++ -g -Wall -std=c++14 setsmaps.cpp -o setsmaps

execute: setsmaps
	./setsmaps

clean:
	rm -f setsmaps