CC = clang++

CC_INCLUDE =
# intentionally no Wall, Wextra, or pedantic to hide errors
# CC_FLAGS = -Wall -Wextra -pedantic
# for extra ridiculousness, disable all warnings
CC_FLAGS = -std=c++11 -O0 -g -w
LD_FLAGS =

TARGETS = exercise1 exercise2 exercise3 exercise4 intlist-test

all: $(TARGETS)

exercise1: exercise1.cpp
	$(CC) $< -o $@ $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS)

exercise2: exercise2.cpp
	$(CC) $< -o $@ $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS)

exercise3: exercise3.cpp
	$(CC) $< -o $@ $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS)

exercise4: exercise4.cpp
	$(CC) $< -o $@ $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS)


intlist.o: intlist.cpp intlist.hpp
	$(CC) $< -o $@ -c $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS)

intlist-test: intlist-test.cpp intlist.hpp intlist.o
	$(CC) $< -o $@ $(CC_INCLUDE) $(LD_FLAGS) $(CC_FLAGS) intlist.o


clean:
	rm -f $(TARGETS)

again: clean $(TARGETS)
