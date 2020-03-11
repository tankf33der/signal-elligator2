all: clean
	gcc -O3 *.c && ./a.out
mike:
	cat *.c >> mike.c
ccomp: clean mike
	ccomp mike.c && ./a.out
interp: clean mike
	ccomp -interp -quiet mike.c
clean:
	rm -rf *.o *.out mike.c

