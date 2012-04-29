CC=gcc
ALL_OBJECT=$(pusubst
%:%c
	$(CC) -o $@ $^
.PHONY: clean all

clean:
	rm *~
