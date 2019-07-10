CC = gcc
CFLAGS = -g -Wall -Werror -pedantic -std=c99
BUILD = slowPrint

all: $(BUILD)

.PHONY: clean
clean:
	rm -f slowPrint
