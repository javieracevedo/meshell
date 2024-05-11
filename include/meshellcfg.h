#pragma once


typedef struct {
        const char* key;
        char* value;
        int (*validate)(char* value);
} cfgitem;



int validate_bg_color(char* value);
int validate_prompt_color(char* value);
int validate_path(char* value);
int validate_start_sound(char* value);
int validate_qotd_list(char* value);
void free_cfg_items(cfgitem* items, int length);
cfgitem* linear_search(cfgitem* items, size_t length, const char* key);
