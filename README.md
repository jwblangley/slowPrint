# Slow Print

This is a command line utility that prints out text at the rate of key presses. The key presses can be random and the text will print as if it was being typed.

## To install
* Clone this repository
* run `make`
	* Note that this project requires the non-standard library `curses.h`. On debian-based systems, you can install this with

		`sudo apt-get install libncurses5-dev libncursesw5-dev`
* (Optional) Add the binary `slowPrint` to your path

## Example usage
`cat example.txt | slowPrint`
