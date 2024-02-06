COMPILER = g++
FLAGS = -std=c++14 -g -Wall
COMPILE = $(COMPILER) $(FLAGS)

out: main.o IntStack.o TestStack.o
	$(COMPILE) main.o IntStack.o TestStack.o -o mainexe

cleanout: clean out

main.o: main.cpp
	$(COMPILE) -c main.cpp

IntStack.o: IntStack.cpp
	$(COMPILE) -c IntStack.cpp

TestStack.o: TestStack.cpp
	$(COMPILE) -c TestStack.cpp

clean:
	rm -f main.o
	rm -f IntStack.o
	rm -f TestStack.o
	rm -f mainexe
