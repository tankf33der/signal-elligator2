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
	fe_frombytes(in, bytes);

	for (i = 0; i < 2; i++) {
		elligator(out, in);
		fe_copy(in, out);
	}

	fe_tobytes(bytes, in);

	for (i = 0; i < 32; i++) {
		printf("%d ", bytes[i]);
	}
	printf("\n");
	return 0;
}
