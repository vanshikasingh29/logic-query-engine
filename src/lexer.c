/*
============================================================

lexer.c

============================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/lexer.h"

static void add_token(
    TokenStream* stream,
    TokenType type,
    const char* text
)
{
    Token* token =
        &stream->tokens[stream->count++];

    token->type = type;

    strcpy(token->text, text);
}

const char* token_type_to_string(
    TokenType type
)
{
    switch(type)
    {
        case TOKEN_SELECT:
            return "SELECT";

        case TOKEN_WHERE:
            return "WHERE";

        case TOKEN_IDENTIFIER:
            return "IDENTIFIER";

        case TOKEN_NUMBER:
            return "NUMBER";

        case TOKEN_GREATER_THAN:
            return "GREATER_THAN";

        case TOKEN_LESS_THAN:
            return "LESS_THAN";

        case TOKEN_EQUAL:
            return "EQUAL";

        case TOKEN_END:
            return "END";

        default:
            return "INVALID";
    }
}

TokenStream tokenize(
    const char* input
)
{
    TokenStream stream;

    stream.count = 0;

    char buffer[64];

    int index = 0;

    while(*input)
    {
        if(isspace(*input))
        {
            input++;
            continue;
        }

        if(isalpha(*input))
        {
            index = 0;

            while(isalnum(*input))
            {
                buffer[index++] = *input++;
            }

            buffer[index] = '\0';

            if(strcmp(buffer,"SELECT")==0)
                add_token(&stream,TOKEN_SELECT,buffer);

            else if(strcmp(buffer,"WHERE")==0)
                add_token(&stream,TOKEN_WHERE,buffer);

            else
                add_token(&stream,TOKEN_IDENTIFIER,buffer);

            continue;
        }

        if(isdigit(*input))
        {
            index = 0;

            while(isdigit(*input))
            {
                buffer[index++] = *input++;
            }

            buffer[index]='\0';

            add_token(
                &stream,
                TOKEN_NUMBER,
                buffer
            );

            continue;
        }

        switch(*input)
        {
            case '>':
                add_token(
                    &stream,
                    TOKEN_GREATER_THAN,
                    ">"
                );
                break;

            case '<':
                add_token(
                    &stream,
                    TOKEN_LESS_THAN,
                    "<"
                );
                break;

            case '=':
                add_token(
                    &stream,
                    TOKEN_EQUAL,
                    "="
                );
                break;

            default:
                add_token(
                    &stream,
                    TOKEN_INVALID,
                    "?"
                );
        }

        input++;
    }

    add_token(
        &stream,
        TOKEN_END,
        "EOF"
    );

    return stream;
}

void print_tokens(
    TokenStream stream
)
{
    printf("\nTokens\n");
    printf("------\n");

    for(int i=0;i<stream.count;i++)
    {
        printf(
            "%-15s %s\n",
            token_type_to_string(
                stream.tokens[i].type
            ),
            stream.tokens[i].text
        );
    }

    printf("\n");
}