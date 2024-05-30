#pragma once
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX_QUOTE_LENGTH 500
#define MAX_QUOTE_LIST_LENGTH 50



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
void free_cfg_items(int length);
cfgitem* linear_search(cfgitem* items, size_t length, const char* key);
void print_config(cfgitem* items, size_t length);
cfgitem* get_cfg_item(char *key); 



