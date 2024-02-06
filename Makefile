out: clean compile execute

compile: bigfive.cpp
	g++ -g -Wall -std=c++14 bigfive.cpp -o bigfive

execute: bigfive
	./bigfive

clean:
	rm -f bigfive