all: rk1

rk1: main.o tasks_rk1.o
	g++ main.o tasks_rk1.o -o out -std=c++11 -Wall

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -Wall

tasks_rk1.o: tasks_rk1.cpp
	g++ -c tasks_rk1.cpp -std=c++11 -Wall

clean:
	rm -rf *.o *.txt out
