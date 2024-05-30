#include "operations.h"
#include <stdio.h>


int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

float divide(int a, int b) {
	return a / b;
}

ssize_t my_getline(char **lineptr, size_t *n, FILE* stream) {
	return 1;
}

ssize_t getline (char **lineptr, size_t *n, FILE *stream)
{
	#ifdef USE_GETLINE
	return my_getline(lineptr, n, stream);
	#else
	return getdelim(lineptr, n, '\n', stream);
	#endif
}


