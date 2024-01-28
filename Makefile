COMPILER = g++
FLAGS = -std=c++14
COMPILE = $(COMPILER) $(FLAGS)

out: main.o IntStack.o
	$(COMPILE) main.o IntStack.o -o mainexe

main.o: main.cpp
	$(COMPILE) -c main.cpp

IntStack.o: IntStack.cpp
	$(COMPILE) -c IntStack.cpp

clean:
	rm main.o; rm IntStack.o; rm mainexe
