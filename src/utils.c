#include <stdio.h>
#include "../include/utils.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

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

char* getstrcpy(char* str, int size) {
        char* copy = (char*)malloc(sizeof(char) * size);
                
        for (int idx = 0; idx < size; idx++) {
                copy[idx] = str[idx];
        }
                        
        copy[size - 1] = '\0';
        return copy;
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

