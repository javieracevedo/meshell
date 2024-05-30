#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>



#include "meshellcfg.h"
#include "utils.h"
#include "parser.h"



// Math Lib

#ifdef USE_GETLINE
#include "../include/custom_math/operations.h"
#include "../include/custom_math/constants.h"
#endif





cfgitem items[] = {    
        {"background_color", NULL, validate_bg_color},    
        {"prompt_color", NULL, validate_prompt_color},    
        {"path", NULL, validate_path},    
        {"start_sound", NULL, validate_start_sound},    
        {"qotd_list", NULL, validate_qotd_list}    
};    


int check_cmd_access(char* command, cfgitem* shell_path) {
        char* path_copy = strdup(shell_path->value);
        char* token = "";

	while (token) {
		token = strsep(&path_copy, ":");
		char* token_copy;
		if (token) {
        		token_copy = strdup(token);
			int token_length = strlen(token_copy);
			if (token_copy[token_length - 1] != '/') {
				token_copy = strcat(token_copy, "/");
			}
		}

		if (token) {
			char* potential_path = strcat(token_copy, command);
			int can_access = access(potential_path, F_OK);
			if (can_access == 0) {
				return can_access;
			}
		}
	}
	return -1;
}

int execute_command(char** command) {
	if (!command) return -1;
    
	pid_t cpid, w;
    	int status;


	size_t cfg_items_length = sizeof(items) / sizeof(cfgitem);
	cfgitem* path = linear_search(items, cfg_items_length, "path");
			
	if (strcmp("exit", command[0]) == 0) {
		exit(EXIT_SUCCESS);
	}

	if (check_cmd_access(command[0], path) == 0) {
		// Message: incomplete, just for testing purposes
		cpid = fork();
		if (cpid == 0) {
			execvp(command[0], command);
		} else {
			do {
				w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
				if (w == -1) {
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
			} while (WIFCONTINUED(status));
		}
	}
			
	int command_length = get_command_length(command);
	for (int i=0; i<command_length; i++) {
		free(command[i]);
	}

	return 0;
}


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

	// system("clear");
	
	FILE* file = fopen("./mishell.rc", "r");
	if (!file) {
		perror("Could not open file.");
		exit(EXIT_FAILURE);
	}


	char* lineptr = NULL;
	size_t n = 0;

	ssize_t gl = getline(&lineptr, &n, file);

	printf("%d\n", gl);
	exit(EXIT_SUCCESS);
	
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

		size_t cfg_items_length = sizeof(items) / sizeof(cfgitem);
		cfgitem* found = linear_search(items, cfg_items_length, lhs);

		if (found) {
			found->value = getstrcpy(rhs, current_buffer_size);
			if (!found->validate(rhs)) {
				printf("%s value is not valid", lhs);
				exit(EXIT_FAILURE);
			}
		}
		free(lhs);
	}


	/*** RANDOM QUOTE OF THE DAY EXAMPLE ***/

	cfgitem qotd_list_config = items[4];

	char* quotes = qotd_list_config.value;
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


	/*** EXAMPLE OF PROMPT COLOR CHANGE ***/


	/*** EXAMPLE OF PLAYING SOUND ***/
	/*if (!PlaySound(TEXT("ateam.wav"), NULL, SND_FILENAME)) {
		printf("ERROR!");
	};
	*/

	/*** EXAMPLE OF COMMAND EXECUTION ***/
	cfgitem path = items[2];
	char command[10] = "hello";
	command[9] = '\0';

	char str[100];
	str[99] = '\0';
	strcat(str, path.value);
	strcat(str, command);

	size_t cfg_items_length = sizeof(items) / sizeof(cfgitem);
	print_config(items, cfg_items_length);

	
	if (shell_mode == INTER)
		shell_loop();
	else
		batch_loop(batch_file_name);			
	
	free_cfg_items(items, cfg_items_length);
	free(buffer);

	return 0;
}


