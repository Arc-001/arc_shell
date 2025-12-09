//
// Created by arc on 12/8/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#define BUFFER_SIZE 1024


void printPrompt() {
    printf("> ");
}

char* readInput() {
    // plan is to increase the buffer size as soon  as it exceeds the buffer size
    int current_length = 0;
    int current_max_length = BUFFER_SIZE;
    char* buffer = malloc(sizeof(char)*BUFFER_SIZE);
    int c;  // as getChar returns an int

    do{
        c = getchar();

        if (current_length >= current_max_length) {
            //TODO: Error handling
            buffer = realloc(buffer, sizeof(char)*(current_max_length+BUFFER_SIZE));
            if (!buffer){
                printf("Memory allocation failed\n");
                exit(0);
            }
            current_max_length += BUFFER_SIZE;
        }

        if (c == EOF || c == '\n') {
            buffer[current_length] = '\0';
            return buffer;
        }else {
            buffer[current_length] = (char)c;
            current_length += 1;
        }
    }while(1);
}

//TODO: Streamed File IO functions