out: clean compile execute

compile: sets.cpp
	g++ -g -Wall -std=c++14 sets.cpp -o sets

execute: sets
	./sets

clean:
	rm -f sets