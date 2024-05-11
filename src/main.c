#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include "../include/meshellcfg.h"


// Resources
// https://benhoyt.com/writings/hash-table-in-c/


// My Library
void cust_getline(FILE* file, char** buffer, int buffer_size) {
	if (!file || !buffer_size) {
		return;
	}

	if (!(*buffer)) {
		*buffer = (char*)malloc(sizeof(char) * buffer_size);
		if (!(*buffer)) {
			perror("Could not allocate memory for line buffer");
			exit(EXIT_FAILURE);
		}
	}

	memset(*buffer, '\0', buffer_size);

	char c;
	int line_idx = 0;
	while ((c = getc(file)) != '\n') {
		if (c == EOF) break;

		(*buffer)[line_idx] = c;
		line_idx++;

		// exceeded the maximum amount of characters in buffer, we need moar
		if (line_idx >= buffer_size - 1) {
			int new_buffer_size = buffer_size * 2;
			char* new_buffer  = (char*)realloc(*buffer, new_buffer_size);
			if (new_buffer) {
				// QUESTION: is there way to use memset here?
				for (int idx = buffer_size; idx < new_buffer_size; idx++) {
					new_buffer[idx] = '\0';
				}
				buffer_size = new_buffer_size;
				(*buffer) = new_buffer;
			}
			else
			{
				perror("Could not allocate more memory for line buffer");
				exit(EXIT_FAILURE);
			}
		}
	}
	(*buffer)[buffer_size - 1] = '\0';
}

char* cust_strsep(char** buffer, int buffer_size, char delim) {
	if (!buffer || !(*buffer)) return NULL;

	char* sub_token = (char*) malloc(sizeof(char) * buffer_size);
	//int buffer_size = 5;
	memset(sub_token, '\0', sizeof(char) * buffer_size);

	// Find delimiter and copy it to sub token
	int idx = 0;
	for (idx = 0; idx < buffer_size; idx++) {
		if ((*buffer)[idx] == delim) {
			(*buffer)[idx] = '\0';
			break;
		}
		sub_token[idx] = (*buffer)[idx];
		(*buffer)[idx] = '\0';
	}

	// this means there is no delimeter, meaning this is the last token
	if (idx == buffer_size) {
		*buffer = sub_token;
		return NULL;
	}

	int count = 0;
	while ((*buffer)[count] == '\0') count++;

	// Shift all the null characters to the right or shift all the characters to the left
	for (int jdx = 0; jdx < count; jdx++) {
		for (int idx = 0; idx < buffer_size; idx++) {
			int next_idx = idx + 1;
			if (next_idx >= buffer_size) {
				break;
			}
			// swap
			char temp = (*buffer)[next_idx];
			(*buffer)[next_idx] = (*buffer)[idx];
			(*buffer)[idx] = temp;
		}
	}

	return sub_token;
}

char* getstrcpy(char *str, int size) {
	char* copy = (char*)malloc(sizeof(char) * size);

	for (int idx = 0; idx < size; idx++) {
		copy[idx] = str[idx];
	}

	copy[size - 1] = '\0';
	return copy;
}


cfgitem items[] = {
	{"background_color", NULL, validate_bg_color},
	{"prompt_color", NULL, validate_prompt_color},
	{"path", NULL, validate_path},
	{"start_sound", NULL, validate_start_sound},
	{"qotd_list", NULL, validate_qotd_list}
};

// Utils
int is_str_alphanum(const char* str, int length) {
	for (int idx = 0; idx < length; idx++) {
		if (str[idx] == '\0') continue;
		if (str[idx] == '_') continue;

		if (!isalnum(str[idx])) {
			return false;
		}
	}
	return true;
}

int main(void) {
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



	// Clean up

	free_cfg_items(items, cfg_items_length);
	free(buffer);

	return 0;
}
