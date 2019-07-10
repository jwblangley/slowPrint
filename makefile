CC = gcc
CFLAGS = -g -Wall -Werror -pedantic -std=c99
LDLIBS = -lcurses

BUILD = slowPrint

all: $(BUILD)

.PHONY: clean
clean:
	rm -f slowPrint
