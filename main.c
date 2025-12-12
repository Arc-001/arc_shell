#include <stdio.h>
#include <stdlib.h>
#include "dispacher.h"
#include "io.h"
#include "parser.h"
#include "builtin.h"


void init() {
    // Initialization code here
}

void loadConfig() {
    // Configuration loading code here
}

void cleanup(){}

void runMainLoop() {
    // Main loop code here
    // initialize variables
    char* line;
    char** parsedCommands;

    while (1) {
        printPrompt();
        //read input
        char* inp = readInput();


        //parse commands
        char** parsed_input = splitter(inp);


        // execute parsed commands
        execute(parsed_input);


    }
}

int main(int argc, char *argv[]) {
    
    // The initialisation
    init();
    loadConfig();

    //The main loop
    runMainLoop();

    //cleanup and exit
    cleanup();

    return EXIT_SUCCESS;
}

