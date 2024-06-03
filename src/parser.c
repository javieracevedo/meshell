#include "../include/parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LINE_LENGTH 1024
// Command includes everything, command name plus arguments
#define MAX_COMMAND_LENGTH 1024
#define MAX_COMMAND_ARGS_LENGTH 1024


/*
 * 	TODO
 * 	
 * 	1. Modify parser to use a struct with the following form { char** command, int argc}
 *	2. 
 *
 * */


int get_command_length(char** command) {
	int count = 0;
	for (int i=0; i<MAX_COMMAND_LENGTH; i++) {
		if (!command[i]) {
			break;
		}
		count++; 
	}

	return count;
}


char** parse_command_line(char* command_line) {
	if (!command_line) {
		return NULL;
	}

	char** command = calloc(MAX_COMMAND_LENGTH, sizeof(char*));
	char* token = strsep(&command_line, " ");
	command[0] = strdup(token);
	int count = 1; 
	while (token) {
		token = strsep(&command_line, " ");
		if (token) { 
			command[count] = strdup(token);
			count++; 
		}
	
	}
	return command;
}

char** prompt_command() {
	long size = pathconf(".", _PC_PATH_MAX);
	char *cwd_buffer = (char *)malloc((size_t)size);
	if (!cwd_buffer) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	getcwd(cwd_buffer, (size_t)size);

	printf("%s > ", cwd_buffer);

	char command_line_buffer[MAX_COMMAND_LINE_LENGTH];
	char* command_line = fgets(command_line_buffer, MAX_COMMAND_LINE_LENGTH, stdin);
	int char_count = 0;

	// QUESTION: is this dangerous
	while (char_count < MAX_COMMAND_LINE_LENGTH && command_line[char_count]) { 
		char_count++;
	}
	// Replace the new line character by a null character
	command_line[char_count - 1] = '\0';

	if (!command_line) {
		perror("Could not read from stdin :: prompt_command");
		exit(EXIT_FAILURE);
	}

	char** command = parse_command_line(command_line);
        
	free(cwd_buffer);
	return command;
}


char** read_batched_command(FILE *file) {
	if (!file) {
		return NULL;
	}
	size_t initial_line_size = 0;
	char* command_line = NULL;
	ssize_t char_count = getdelim(&command_line, &initial_line_size, '\n', file);

	if (!command_line || strcmp(command_line, "") == 0 || strcmp(command_line, "\n") == 0) {
		// TODO: define globally when to return NULL, and how to handle NULL values within functions
		// I need to come up with a personal convention for this
		return NULL;
	}

	// Replace the new line character by a null character
	command_line[char_count - 1] = '\0';

	if (!command_line) {
		perror("Could not read from file :: read_batched_command");
		exit(EXIT_FAILURE);
	}

	char** command = parse_command_line(command_line);
        
	return command;
}

