#include <stdlib.h>
#include <time.h>

int ClienteChegou() { return rand() % 3; }

int Transacao() {

  int transacao = rand() % 5;

  switch (transacao) {
  case 0:
    return 10;
  case 1:
    return 20;
  case 2:
    return 30;
  case 3:
    return 40;
  case 4:
    return 50;
  default:
    return -1;
  }
}
