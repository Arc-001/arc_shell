//
// Created by arc on 12/12/25.
//
#include "builtin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* builtin_cmd[]={
    "cd",
    "exit"
};

int (*builtin_func[])(char**)={
    &builtinCD,
    &builtinEXIT
};

int builtinSIZE() {
    return (int)(sizeof(builtin_cmd)/sizeof(char*));
}


int builtinCD(char** args) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing operand\n");
        return 1;
    }
    if (args[2] != NULL) {
        fprintf(stderr, "cd: too many arguments\n");
        return 1;
    }
    if (chdir(args[1]) != 0) {
        fprintf(stderr,"cd: cannot change directory, %s is invalid", args[1]);
    }
    return 1;
}

int builtinEXIT(char** args) {
    exit(EXIT_SUCCESS);
}