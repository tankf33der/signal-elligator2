#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fe.h"
#include "crypto_additions.h"

int main(void) {
	int i;
	unsigned char bytes[32];
	fe in, out;

	for (i = 0; i < 32; i++) {
		bytes[i] = i;
	}

	for (i = 0; i < 100000; i++) {
		bytes[31] &= 0x3f;

		fe_frombytes(in, bytes);
		elligator(out, in);
		fe_tobytes(bytes, out);
	}


	for (i = 0; i < 32; i++) {
		printf("%d ", bytes[i]);
	}
	printf("\n");
	return 0;
}
