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
        command->args = (char**)calloc(1024, sizeof(char *));
}


Command* parse_command_line(char* command_line) {
	if (!command_line) {
		return NULL;
	}

        Command* command = init_command_struct();
	char* command_name = strsep(&command_line, " ");
	if (command_name && strcmp(command_name, "\n") != 0) {
		command->command = strdup(command_name);
	} else {
		return NULL;
	}
	
	char* token = command_line;
	int count = 0; 
	while (token) {
		token = strsep(&command_line, " ");
		if (token) {
			command->args[count] = token;
			count++; 
		}
	}
	command->argc = count;
	return command;
}

Command* prompt_command() {
        printf("~/home/ ");                                      
	char command_line_buffer[MAX_COMMAND_LINE_LENGTH];
	char* command_line = fgets(command_line_buffer, MAX_COMMAND_LINE_LENGTH, stdin);

	if (!command_line) {
		perror("Could not read from stdin :: prompt_command");
		exit(EXIT_FAILURE);
	}

	Command* command = parse_command_line(command_line);
        return command;
}

