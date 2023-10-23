ned: ned.c
	gcc -g -Wall -Wextra -o ned ned.c

run: ned
	./ned

clean:
	rm ned
