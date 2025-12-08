#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
        int c = 0;
        //parse commands
        // execute parsed commands
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

