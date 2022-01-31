all: autoedit

autoedit: autoedit.c autoedit.h
	gcc -g -O -o autoedit autoedit.c
