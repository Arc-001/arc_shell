//
// Created by arc on 12/12/25.
//

#ifndef ARC_SHELL_BUILTIN_H
#define ARC_SHELL_BUILTIN_H
int builtinCD(char** args);
int builtinEXIT(char** args);
int builtinSIZE();
extern char *builtin_cmd[];
extern int (*builtin_func[])(char**);

int execute(char** args);
#endif //ARC_SHELL_BUILTIN_H