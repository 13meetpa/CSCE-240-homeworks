flags = -std=c++17 -Wall -I .

hw2functions.o : hw2functions.cpp hw2functions.h
	g++ $(flags) -c $< -I .

hw2 : hw2.cpp hw2functions.o
	g++ $(flags) $^ -o $@

checkit : checkit.cpp
	g++ $(flags) $^ -o $@

hw2test1 : hw2 checkit test1-input.txt correct-test1.txt
	./hw2 test1-input.txt > student-test1.txt
	./checkit 0

hw2test2 : hw2 checkit test2-input.txt correct-test2.txt
	./hw2 test2-input.txt > student-test2.txt
	./checkit 1

clean :
	rm student-test*txt checkit hw2 *.o 

