CC=g++
tsp: node.h nodecmp.h node.cpp tsp.cpp
	$(CC) -o tsp -O2 $^
run: tsp
	./tsp data.txt
clean:
	rm tsp
PHNOY: all run clean

