#pragma once

typedef enum {
	BATCH,
	INTER
} Mode;


int get_command_length(char ** command);
char** init_command_struct();
char** prompt_command();
char** read_batched_command();
