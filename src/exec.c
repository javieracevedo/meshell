#include "../include/exec.h"
#include <unistd.h>
#include <sys/wait.h>
#include "../include/parser.h"
#include "../include/meshellcfg.h"
#include "../include/utils.h"


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


	cfgitem* path = get_cfg_item("path");	
	if (!path) {
		printf("Could not find path if item in shell config\n");
		exit(EXIT_FAILURE);
	}

	char* command_name = command[0];
	

	if (strcmp(command_name, "exit") == 0) {
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(command_name, "path") == 0) {
		int argc = get_command_length(command);
		if (argc == 1) {
			printf("%s\n", path->value);
			return  0;
		}

		for (int i = 1; i <= argc - 1; i++) {
			// TODO: ideally, commands should be trimmed, so this wouldn't be needed here
			if (strcmp(command[i], "") == 0) {
				continue;
			}
			strcat(path->value, ":");
			strcat(path->value, command[i]);
		}
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
