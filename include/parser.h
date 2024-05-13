#pragma once

typedef enum {
	BATCH,
	INTERP
} Mode;

typedef struct {
	char* command;
	char** args;
	int argc;
} Command;


Command* init_command_struct();
Command* prompt_command();

