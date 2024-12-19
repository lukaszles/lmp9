all:
	gcc -Wall --pedantic src/*.c -o bin

test: all
	bin dane/A dane/b
