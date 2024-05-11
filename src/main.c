#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#include "../include/meshellcfg.h"
#include "../include/utils.h"
#include "../include/parser.h"

        

void shell_loop(Mode mode) {
        while (true) {
                if (mode == BATCH) {
                        puts("Shell is in batch mode");
                }
                else {
                        Command* command = prompt_command();
			if (strcmp("exit", command->command) == 0) {
				exit(EXIT_SUCCESS);
			}
                        system(command->command);
                        free(command->args);
                        free(command->command);
                        free(command);
                }
        }
}



cfgitem items[] = {
	{"background_color", NULL, validate_bg_color},
	{"prompt_color", NULL, validate_prompt_color},
	{"path", NULL, validate_path},
	{"start_sound", NULL, validate_start_sound},
	{"qotd_list", NULL, validate_qotd_list}
};


int main(void) {
	system("clear");
	
	FILE* file = fopen("./mishell.rc", "r");
	if (!file) {
		perror("Could not open file.");
		exit(EXIT_FAILURE);
	}

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
	

	Mode mode = INTERP;
	shell_loop(mode);
	
	free_cfg_items(items, cfg_items_length);
	free(buffer);

	return 0;
}
