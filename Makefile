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
src/optimiser.c



OUTPUT=query_engine



all:

	$(CC) $(CFLAGS) $(SRC) -I$(INCLUDE) -o $(OUTPUT)



run:

	./$(OUTPUT)



clean:

	rm -f $(OUTPUT) test_engine



debug:

	gdb ./$(OUTPUT)





##################################################
# Test Suite
##################################################


TEST_SRC=tests/test_engine.c \
src/relation.c \
src/executor.c \
src/parser.c \
src/lexer.c \
src/ast.c



TEST_OUTPUT=test_engine




test:

	$(CC) $(CFLAGS) $(TEST_SRC) -I$(INCLUDE) -o $(TEST_OUTPUT)

	./$(TEST_OUTPUT)