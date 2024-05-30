#include "../include/meshellcfg.h"


cfgitem items[] = {    
       	{"background_color", NULL, validate_bg_color},    
        {"prompt_color", NULL, validate_prompt_color},    
        {"path", NULL, validate_path},    
        {"start_sound", NULL, validate_start_sound},    
        {"qotd_list", NULL, validate_qotd_list}    
};  




cfgitem* linear_search(cfgitem* items, size_t length, const char* key) {
        for (size_t i = 0; i < length; i++) {
                if (strcmp(items[i].key, key) == 0) {
                        return &items[i];
                }
        }
        return NULL;
}


cfgitem* get_cfg_item(char *key) {
	size_t cfg_items_length = sizeof(items) / sizeof(cfgitem);
	cfgitem* item = linear_search(items, cfg_items_length, key);
	return item;
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


void free_cfg_items(int length) {
        // QUESTION: why do I need to get the address of items here and then derefference?
        for (size_t i = 0; i < length; i++) {
                if (items[i].value) {
                        free(items[i].value);
                }
        }
}


