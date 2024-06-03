#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


#include "../include/meshellcfg.h"
#include "../include/utils.h"
#include "../include/parser.h"
#include "../include/exec.h"


#define CONFIG_LINE_MAX_SIZE 1024


void batch_loop(char* batch_file_name) {
	FILE* batched_commands_file = fopen(batch_file_name, "r");
	if (!batched_commands_file) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
       
	while (true) {
		char** command = read_batched_command(batched_commands_file);
		if (!command || feof(batched_commands_file)) break;
		execute_command(command);
        }

	// TODO: remember to free stuff here

}


void shell_loop() {
	while (true) {
		char** command = prompt_command(); 
		execute_command(command);
        }

	// TODO: remember to free stuff here
}


int main(int argc, char** argv) {
	char* batch_file_name = NULL;
	Mode shell_mode;

	if (argc < 2) {
		shell_mode = INTER;
	} else {
		shell_mode = BATCH;
		batch_file_name = argv[1];
	}

	system("clear");
	
	FILE* file = fopen("./mishell.rc", "r");
	if (!file) {
		perror("Could not open file.");
		exit(EXIT_FAILURE);
	}

	init_cfgitems();

	char* buffer = NULL;
	int buffer_size = 6; // Considering null character

	while (!feof(file)) {
		// QUESTION: figure out the largest string you can hold in buffer, then handle that somehow? I don't know what should I do with this. But it shouldn't be a problem for now.
		cust_getline(file, &buffer, buffer_size);
		if (strcmp(buffer, "") == 0) break;

		// TODO: maybe I need to set a maximum size per line, so we can avoid using strlen on pretty large lines??
		// or maybe implement your own strlen, with an exit condition after certain amount of iterations?
		int current_buffer_size = strlen(buffer);
		char* lhs = cust_strsep(&buffer, current_buffer_size, '=');
		char* rhs = buffer;

		int is_valid_lhs = lhs && is_str_alphanum(lhs, current_buffer_size);
		if (!is_valid_lhs) {
			printf("Configuration file could not be read: invalid LHS value\n");
			exit(EXIT_FAILURE);
		}

		cfgitem* found = get_cfg_item(lhs);
		if (found) {
			int max_idx = current_buffer_size;
			if (current_buffer_size > CONFIG_LINE_MAX_SIZE) max_idx = CONFIG_LINE_MAX_SIZE;
			
			// TODO: this does not consider what happens if found->value has not beed malloced
			for (int idx=0; idx<max_idx; idx++) found->value[idx] = rhs[idx];

			if (!found->validate(found->value)) {
				printf("%s value is not valid", lhs);
				exit(EXIT_FAILURE);
			}
		}
		free(lhs);
	}


	/*** RANDOM QUOTE OF THE DAY EXAMPLE ***/

	cfgitem* qotd_list_config = get_cfg_item("qotd_list");
	if (!qotd_list_config) {
		printf("Could not find config item in config list");
		exit(EXIT_FAILURE);
	}

	char* quotes = qotd_list_config->value;
	int buffer_size_quotes = strlen(quotes);
	char* token;
	char* quote_list[MAX_QUOTE_LIST_LENGTH];
	int string_count = 0;

	do {
		token = cust_strsep(&quotes, buffer_size_quotes, ',');
		
		if (!token) {
			quote_list[string_count] = quotes;
		}
		else {
			quote_list[string_count] = token;
		}

		string_count++;
		if (string_count >= MAX_QUOTE_LIST_LENGTH) {
			printf("Maximum amount of quotes reached, only 50 will be considered.");
			break;
		}
	} while (token);

	srand(time(NULL));

	int random_idx = rand() % string_count;
	const char* random_string = quote_list[random_idx];

	printf("qotd: \"%s.\" \n", random_string);
	
	if (shell_mode == INTER)
		shell_loop();
	else
		batch_loop(batch_file_name);			
	
	free_cfg_items();
	free(buffer);

	return 0;
}


