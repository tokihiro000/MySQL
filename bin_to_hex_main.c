#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_to_hex.c"
#include "../pseudo_random.c"

int main(void) {
  unsigned char *r, *hex_char;

  r = pseudo_random(32);

  hex_char = bin_to_hex(r, 32);

  return 0;
}
