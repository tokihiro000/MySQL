#include <stdio.h>
#include "memcat.c"
#include "pseudo_random.c"

int main(void) {
  char str[100] = "megane(' ";
  char *ptr = " ')";
  unsigned char *r;

  r = pseudo_random(10);
  memcat(str, ptr, r,10);
}
