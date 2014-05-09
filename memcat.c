#include <string.h>

char *memcat(char *str, char *ptr, unsigned char *binary, int bin_len) {
  int str_len, ptr_len;

  str_len = strlen(str);
  memcpy(&str[str_len], binary, bin_len);

  ptr_len = strlen(ptr);
  memcpy(&str[str_len + bin_len], ptr, ptr_len);

  return str;
}

