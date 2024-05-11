#include "../include/parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_COMMAND_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_COMMAND_ARGS_LENGTH 1024


Command* init_command_struct() {
        Command* command = (Command*)malloc(sizeof(Command));
        command->command = (char*)malloc(sizeof(char) * MAX_COMMAND_LENGTH);
        command->args = (char*)malloc(sizeof(char) * MAX_COMMAND_ARGS_LENGTH);
}


Command* prompt_command() {
        printf("~/home/ ");                                      
        Command* command = init_command_struct();
	char command_line[MAX_COMMAND_LINE_LENGTH];
	char* result = fgets(command_line, MAX_COMMAND_LINE_LENGTH, stdin);

	if (!result) {
		perror("Could not read from stdin :: prompt_command");
		exit(EXIT_FAILURE);
	}
	
	command->command = strdup(result);
        return command;
}


