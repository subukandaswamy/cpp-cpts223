out: clean compile execute

compile: usets.cpp
	g++ -g -Wall -std=c++14 usets.cpp -o usets

execute: usets
	./usets

clean:
	rm -f usets