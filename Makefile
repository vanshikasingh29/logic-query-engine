CC=gcc


CFLAGS=-Wall -Wextra -std=c17 -g



SRC=src/main.c src/parser.c src/relation.c src/executor.c


TARGET=query_engine



all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)



run:
	./$(TARGET)



test:
	$(CC) $(CFLAGS) src/parser.c src/relation.c src/executor.c tests/query_tests.c -o query_tests
	./query_tests



clean:
	rm -f $(TARGET)
	rm -f query_tests