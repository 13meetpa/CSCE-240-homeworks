flags = -std=c++17 -Wall -I .

timeofday.o : timeofday.cpp timeofday.h
	g++ $(flags) -c $< -I .

testtimeofday : testtimeofday.cpp timeofday.o
	g++ $(flags) $^ -o $@

checkit : checkit.cpp
	g++ $(flags) $^ -o $@

checktimeofday : testtimeofday checkit correct-testtimeofday.txt
	./testtimeofday  > student-testtimeofday.txt
	./checkit 0

timeinterval.o : timeinterval.cpp timeinterval.h timeofday.h
	g++ $(flags) -c $< -I .

testtimeinterval : testtimeinterval.cpp timeinterval.o timeofday.o
	g++ $(flags) $^ -o $@

checktimeinterval : testtimeinterval checkit correct-testtimeinterval.txt
	./testtimeinterval  > student-testtimeinterval.txt
	./checkit 1

clean :
	rm student-test*txt *.o checkit testtimeofday testtimeinterval

