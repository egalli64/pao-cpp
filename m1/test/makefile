OBJS = buggy_factorial.o buggy_negator.o
TEST_OBJS = test_factorial.o test_negator.o

.PHONY: all clean

all: main test

main: main.o $(OBJS)
	g++ -o main main.o $(OBJS)

test: doctest.o $(OBJS) $(TEST_OBJS)
	g++ -o test doctest.o $(OBJS) $(TEST_OBJS)

main.o: buggy_factorial.h buggy_negator.h

doctest.o: buggy_factorial.h buggy_negator.h

test_factorial.o: buggy_factorial.h

test_negator.o: buggy_negator.h

clean:
	rm -f main test main.o doctest.o $(OBJS) $(TEST_OBJS)
