# use g++ compiler
cc = g++

# compile with C++ 17 standard
flags = -std=c++17
# compile with all warnings
flags += -Wall
# compile with PWD appended to compiler library path
flags += -I $(path)
# compile with debug instrumentation
flags += -g

# compile, assemble, link
link = $(cc) $(flags) -o
# compile, assemble, do not link
compile = $(cc) $(flags) -c

test-find-sum : test-find-sum.o find-sum.o
	$(link) $@ $^

test-find-sum-all : test-find-sum
	@echo 'Running All Tests' \
  && ./test-find-sum row_matrix.txt 0  \
	&& ./test-find-sum col_matrix.txt 1  \
	&& ./test-find-sum matrix.txt 4  \
	&& ./test-find-sum matrix.txt 5


test-find-sum.o : test_find_sum.cpp test_find_sum.h find_sum.h
	$(compile) -o $@ $<

find-sum.o : find_sum.cpp find_sum.h
	$(compile) -o $@ $<


clean:
	$(RM) *.o test-find-sum
