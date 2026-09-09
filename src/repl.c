#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "perx_modules.h"

/**
 * Implements the read-evaluate-print-loop (REPL) for the perx shell
 * it continuously asks for user input and handles the execution
 */
void repl() {
    
    // # start the continuous loop for the shell
    do {

        // # disable output buffering to show prompt immediately
        setbuf(stdout, NULL);

        // # display the shell prompt
        printf("(perx) $ ");

        // # array to hold the user input
        char input[1024];
        
        // # get the input typed by the user
        fgets(input, sizeof(input), stdin);
        
        // # remove the new line character at the end of the string
        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input, "exit") == 0) {
            printf("exited from perx shell\n");
            return;
        }

        // # temporarily print command not found for all inputs
        printf("%s: command not found\n\n", input);

    } while(1);

}