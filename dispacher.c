//
// Created by arc on 12/9/25.
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include "builtin.h"
#include "dispacher.h"

int execute(char** args) {

    if (args == NULL || args[0] == NULL) {
        return 1;
    }

    for (int i = 0; i < builtinSIZE(); i++) {
        if (strcmp(args[0], builtin_cmd[i])==0) {
            return (*builtin_func[i])(args);
        }
    }
    dispacher(args);
    return 0;
}


void dispacher(char **args) {
    pid_t pid;
    pid_t wpid;
    int status;

    //workflow
    // 1) we fork and make a clone child
    // 2) the child then transforms to the required process by exec
    // 3) we keep tabs on the child by the returned pid and wait

    pid = fork();
    if (pid == 0) {
        //Child Process

        //note that the v means it accepts vectors and p means OS searches the name
        //eg. htop is same as /bin/htop for p as that location is fetched by os
        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0 ) {
        // Parent Process


        do {
            //we check the status till either signal tem by ctrl+c or exited by natural termination
            //WUNTRACED is to be signaled when the prohram stops (ctrl+Z)
            wpid = waitpid(pid, &status, WUNTRACED);
            if (WIFSTOPPED(status)) {
                printf("[%d]- Stopped by signal %d", wpid, WSTOPSIG(status));
            }
        }while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("fork failed");
    }
}
