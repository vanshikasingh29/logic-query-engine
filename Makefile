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


TEST_ENGINE=test_engine

SET_TESTS=set_tests

RELATION_TESTS=relation_tests

FUNCTION_TESTS=function_tests


TEST_ENGINE_SRC=tests/test_engine.c \
src/relation.c \
src/executor.c \
src/parser.c \
src/lexer.c \
src/ast.c


SET_TEST_SRC=tests/test_sets.c \
src/set.c \
src/relation.c


RELATION_TEST_SRC=tests/test_binary_relation.c \
src/binary_relation.c


FUNCTION_TEST_SRC=tests/test_functions.c \
src/function.c


all:

	$(CC) $(CFLAGS) $(SRC) -I$(INCLUDE) -o $(OUTPUT)


run:

	./$(OUTPUT)


test-engine:

	$(CC) $(CFLAGS) \
	$(TEST_ENGINE_SRC) \
	-I$(INCLUDE) \
	-o $(TEST_ENGINE)

	./$(TEST_ENGINE)


test-sets:

	$(CC) $(CFLAGS) \
	$(SET_TEST_SRC) \
	-I$(INCLUDE) \
	-o $(SET_TESTS)

	./$(SET_TESTS)


test-relations:

	$(CC) $(CFLAGS) \
	$(RELATION_TEST_SRC) \
	-I$(INCLUDE) \
	-o $(RELATION_TESTS)

	./$(RELATION_TESTS)


test-functions:

	$(CC) $(CFLAGS) \
	$(FUNCTION_TEST_SRC) \
	-I$(INCLUDE) \
	-o $(FUNCTION_TESTS)

	./$(FUNCTION_TESTS)


test-all: test-engine test-sets test-relations test-functions


clean:

	rm -f $(OUTPUT) \
	$(TEST_ENGINE) \
	$(SET_TESTS) \
	$(RELATION_TESTS) \
	$(FUNCTION_TESTS)


debug:

	gdb ./$(OUTPUT)