#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <curses.h>

#include "slowPrint.h"

#define BUFFER_SIZE 1024
#define ESC 27

int main(int argc, char **argv)
{
	char* inputted = readUntilEOF();

	printByCharOnPress(inputted);

	return 0;
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

void printByCharOnPress(char* toPrint) {
	// setup new screen
	initscr();
	cbreak();
	noecho();

	getch();

	bool end_of_input = false;
	int i = 0;
	int c = -1;
	do {
		// wait for keypress
		c = getch();

		if (!end_of_input) {
			// get character of input
			char c_from_input = toPrint[i++];

			if (c_from_input == '\0') {
				end_of_input = true;
				printw("End of inputted string. Press ESC to quit\n");
			} else {
				printw("%c", c_from_input);
			}
			refresh();
		}

	} while(c != ESC);

	// Close screen
	endwin();
}
