#include <stdlib.h>
#include <stdio.h>

#include "fe.h"

void main(void) {
	int i;
	unsigned char bytes[32];
	fe in, out;

	for (i = 0; i < 32; i++) {
		bytes[i] = i;
	}
	fe_frombytes(in, bytes);
	elligator(out, in);
	fe_tobytes(bytes, out);
	printf("%d\n", bytes[0]);

}
