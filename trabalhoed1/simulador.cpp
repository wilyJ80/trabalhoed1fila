#include "rotinas.h"
#include "tad_fila_estatica_circular.h"
#include <stdio.h>

#define FINAL 100

int crono, espera, totcli, client;
int caixa[3];
struct T_Fila fila;
struct T_Item item;

int main(void) {

  crono = 0, espera = 0, totcli = 0;

  iniciarFila(&fila);

  while (crono < FINAL) {

    if (ClienteChegou()) {

      inserir(&fila, crono);
    }
  }
}
