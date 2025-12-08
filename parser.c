#define Token_MAX 100
#define delim " \t\r\n\a"
#include <stdlib.h>
#include <string.h>

char **splitter(char *input) {
    
    int current_buffer = Token_MAX;
    int position = 0;

    char **tokens = malloc(current_buffer * sizeof(char *));
    char *token;

    //splitting
    token = strtok(input, delim);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= current_buffer){
            current_buffer += Token_MAX;
            tokens = realloc(tokens, current_buffer * sizeof(char *));
        }
        
        //this just gets the next token

        token = strtok(NULL, delim);
    }
}

