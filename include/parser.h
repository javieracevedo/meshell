#pragma once

typedef enum {
	BATCH,
	INTERP
} Mode;


int get_command_length(char ** command);
char** init_command_struct();
char** prompt_command();

