CC=gcc
%:%c
	$(CC) -o $@ $^
.PHONY: clean all

clean:
	rm *~
