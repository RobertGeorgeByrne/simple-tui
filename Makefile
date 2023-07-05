all: com run

run:
	./simpletui

com:
	gcc -Wall -Wextra simpletui.c -o simpletui
