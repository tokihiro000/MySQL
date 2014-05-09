unsigned char *bin_to_hex (unsigned char *binary, int bin_len) {
  unsigned char *hex;
  char str[10];
  int i;

  hex = (unsigned char *)malloc(sizeof(unsigned char) * (bin_len * 2));
  memset(hex, 0x00, sizeof(unsigned char) * (bin_len * 2));

  printf("bin:");
  for(i = 0; i < bin_len; i++)
    {
      printf("%02x", binary[i]);
    }
  putchar('\n');

  for(i = 0; i < bin_len; i++)
    {
      sprintf(str, "%02x", binary[i]);
      strcat((char *)hex, str);
    }
  printf("hex:%s\n", hex);

  return hex;
}
