//
// Created by arc on 12/9/25.
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "dispacher.h"
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
