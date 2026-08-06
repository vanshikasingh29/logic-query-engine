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

	rm -f $(OUTPUT)



debug:

	gdb ./$(OUTPUT)