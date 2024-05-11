#include "../include/parser.h"
#include <stdlib.h>
#include <stdio.h>


Command* init_command_struct() {
        Command* command = (Command*)malloc(sizeof(Command));
        command->command = (char*)malloc(sizeof(char) * 1024);
        command->args = (char*)malloc(sizeof(char) * 1024);
}


Command* prompt_command() {
        printf("~/home/ ");                                      
        Command* command = init_command_struct();
        scanf("%s", command->command);
        return command;
}
