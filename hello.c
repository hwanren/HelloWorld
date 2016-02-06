#include <stdio.h>
#include <stdlib.h>

struct rec {
  int i;
  float f;
};

int main(int argc, char**argv)
{
  struct rec *p;

  printf("Hello World!\n");

  p = (struct rec *)malloc(sizeof(struct rec));
  p->i = 1;
  p->f = 1.0;
  printf("a new record of (%d, %f) created\n", p->i, p->f);

  /* Comment out the following free(p) to see if static analyzer picks it. */
  /* free(p); */

  return 0;
}
