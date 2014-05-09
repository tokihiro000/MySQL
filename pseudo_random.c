/////////////////////////////////////////////////////////////////////
//
//     疑似乱数生成器
//
//     byte_lenバイトの乱数を生成し、それを返す
//

#include <stdio.h>
#include <openssl/evp.h>


unsigned char *pseudo_random(int byte_len)
{
  int i,k;
  unsigned char *prandom;

  RAND_poll();
  RAND_load_file("/dev/random",1024);
  while (RAND_status() == 0) {
    printf("status = 0\n");
    RAND_load_file("/dev/random",1024);
  }
 
  prandom = (unsigned char *)malloc(sizeof(unsigned char) * byte_len);
  RAND_bytes(prandom, byte_len);
 
  printf("prandom = ");
  for(i = 0; i < byte_len; i++)
    {
      printf("%02x", prandom[i]);
    }
  putchar('\n');
  
  return prandom;
 
}

/* int main(void){ */
/*   int num; */
/*   unsigned char *r; */
/*   printf("何バイトの乱数を生成します？:"); */
/*   scanf("%d", &num); */
  
/*   r = pseudo_random(num); */
  
  
/*   return 0; */
/* } */
