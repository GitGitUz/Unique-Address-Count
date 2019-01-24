all: test

test: count.c
	gcc -Wall -Werror -fsanitize=address count.c -lm -o count
clean:
	rm -rf count

