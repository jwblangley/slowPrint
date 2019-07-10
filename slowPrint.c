#include <stdio.h>
#include <stdlib.h>

#include "slowPrint.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	char* inputted = readUntilEOF();
	printf("%s\n", inputted);
	return (0);
}

char* readUntilEOF() {
	char* txt = malloc(sizeof(char) * BUFFER_SIZE);
	int txt_len = BUFFER_SIZE;
	int txt_index = 0;

	char c;
	while ((c = getchar()) != EOF) {
		// If about to exceed buffer, increase by BUFFER_SIZE
		// Remember extra for null terminator
		if (txt_index >= txt_len - 1) {
			txt_len += BUFFER_SIZE;
			txt = realloc(txt, txt_len);
		}
		// Store the character and increment index
		txt[txt_index++] = c;
	}
	// Add null terminator
	txt[txt_index] = '\0';

	return txt;
}
