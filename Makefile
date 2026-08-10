CC=gcc

CFLAGS=-Wall -Wextra -std=c17 -g

INCLUDE=include


SRC=src/main.c \
src/parser.c \
src/lexer.c \
src/ast.c \
src/relation.c \
src/executor.c \
src/planner.c \
src/expression.c \
src/storage.c \
src/optimiser.c \
src/set.c \
src/binary_relation.c


OUTPUT=query_engine

TEST_OUTPUT=test_engine

SET_TEST_OUTPUT=set_tests

RELATION_TEST_OUTPUT=relation_tests


TEST_SRC=tests/test_engine.c

SET_TEST_SRC=tests/test_sets.c

RELATION_TEST_SRC=tests/test_binary_relation.c


all:
	$(CC) $(CFLAGS) $(SRC) -I$(INCLUDE) -o $(OUTPUT)


run:
	./$(OUTPUT)


test:
	$(CC) $(CFLAGS) \
	$(TEST_SRC) \
	src/relation.c \
	src/executor.c \
	src/parser.c \
	src/lexer.c \
	src/ast.c \
	-I$(INCLUDE) \
	-o $(TEST_OUTPUT)

	./$(TEST_OUTPUT)


test-sets:
	$(CC) $(CFLAGS) \
	$(SET_TEST_SRC) \
	src/set.c \
	src/relation.c \
	-I$(INCLUDE) \
	-o $(SET_TEST_OUTPUT)

	./$(SET_TEST_OUTPUT)


test-relations:
	$(CC) $(CFLAGS) \
	$(RELATION_TEST_SRC) \
	src/binary_relation.c \
	-I$(INCLUDE) \
	-o $(RELATION_TEST_OUTPUT)

	./$(RELATION_TEST_OUTPUT)


test-all: test test-sets test-relations


debug:
	gdb ./$(OUTPUT)


clean:
	rm -f $(OUTPUT) \
	$(TEST_OUTPUT) \
	$(SET_TEST_OUTPUT) \
	$(RELATION_TEST_OUTPUT)