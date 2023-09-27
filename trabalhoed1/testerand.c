#include "rotinas.h"
#include <stdio.h>

int main(void) {
  char ch;

  for (;;) {
    printf("deseja aleatorio?");
    scanf(" %c", &ch);

    printf("%d\n\n", Transacao());
  }

  return 0;
}
