#include "../include/meshellcfg.h"


cfgitem* linear_search(cfgitem* items, size_t length, const char* key) {
        for (size_t i = 0; i < length; i++) {
                if (strcmp(items[i].key, key) == 0) {
                        return &items[i];
                }
        }
        return NULL;
}


int validate_bg_color(char *value) {
	// QUESTION: what should I use instead of strlen here?
	for (int idx = 0; idx < strlen(value); idx++) {
		if (!isalpha(value[idx])) {
			return false;
		}
	}
	return true;
}


int validate_prompt_color(char* value) {
        // QUESTION: what should I use instead of strlen here?
        for (int idx = 0; idx < strlen(value); idx++) {
                if (!isalpha(value[idx])) {
                        return false;
                }
        }
        return true;
}

int validate_path(char* value) {
        int result = false;
        for (int idx = 0; idx < strlen(value); idx++) {
                if (isalpha(value[idx]) || value[idx] == '\\' || value[idx] == '/' || value[idx] == ':' || value[idx] == '~' || value[idx] == '.') {
                        result = true;
                }
                else {
                        result = false;
                }
        }
        return result;
}

int validate_start_sound(char* value) {
        int result = false;
        for (int idx = 0; idx < strlen(value); idx++) {
                if (isalpha(value[idx]) || isdigit(value[idx]) || value[idx] == '\\' || value[idx] == '/' || value[idx] == ':' || value[idx] == '~' || value[idx] == '.') {
                        result = true;
                }
                else {
                        result = false;
                }
        }
        return result;
}

int validate_qotd_list(char* value) {
        // TODO: pick an actual length
        return strlen(value) <= MAX_QUOTE_LENGTH;
}


void print_config(cfgitem* items, size_t length) {
        printf("\n======================================================\n\n");
        printf("Current shell config:\n\n\n");
        for (size_t i = 0; i < length; i++) printf("%s: %s \n", items[i].key, items[i].value);
        printf("\n======================================================\n\n");
}


void free_cfg_items(cfgitem* items, int length) {
        // QUESTION: why do I need to get the address of items here and then derefference?
        for (size_t i = 0; i < length; i++) {
                if (items[i].value) {
                        free(items[i].value);
                }
        }
}

