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
src/set.c


OUTPUT=query_engine


SET_TEST_OUTPUT=set_tests


SET_TEST_SRC=tests/test_sets.c \
src/relation.c \
src/set.c



all:
	$(CC) $(CFLAGS) $(SRC) -I$(INCLUDE) -o $(OUTPUT)



run:
	./$(OUTPUT)



test:
	$(CC) $(CFLAGS) $(SET_TEST_SRC) -I$(INCLUDE) -o $(SET_TEST_OUTPUT)
	./$(SET_TEST_OUTPUT)



clean:
	rm -f $(OUTPUT) $(SET_TEST_OUTPUT)



debug:
	gdb ./$(OUTPUT)