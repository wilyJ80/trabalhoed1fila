#include "rotinas.h"
#include "tad_fila_estatica_circular.h"
#include <stdio.h>

#define FINAL 40

int espera, totcli, client;
int caixa[3] = {0, 0, 0};
struct T_Fila fila;
struct T_Item crono;

int main(void) {

  srand((unsigned)time(NULL));

  espera = 0, totcli = 0;
  crono.campo = 0;

  iniciarFila(&fila);

  printf("INICIO\n\n");
  while (crono.campo < FINAL) {

    // teste
    printf("FILA: ");
    exibir(&fila);
    printf("\n");

    if (ClienteChegou()) {

      inserir(&fila, crono);

      // teste
      printf("Cliente entrou na fila.\n");
      printf("FILA: ");
      exibir(&fila);
      printf("\n");

      totcli++;
    }

    for (int i = 0; i < 3; i++) {

      if (!chkFilaVazia(&fila) && caixa[i] == 0) {

        client = remover(&fila);

        // teste
        printf("Cliente saiu da fila.\n");
        printf("FILA: ");
        exibir(&fila);
        printf("\n");

        espera += (crono.campo - client);

        caixa[i] = Transacao();
      }
    }

    for (int i = 0; i < 3; i++) {

      if (caixa[i] != 0) {
        caixa[i]--;
      }
    }

    crono.campo++;
    printf("\n************************\nCRONOMETRO: %d\n", crono.campo);
  }

  printf("\n");
  printf("Tempo de atendimento: %d\n", FINAL);
  printf("Total de clientes: %d\n", totcli);
  printf("Tempo total de espera: %d\n", espera);

  if (totcli > 0) {
    double tempomedioespera = ((double)espera / totcli);
    printf("Tempo medio de espera: %f\n\n", tempomedioespera);

  } else {

    printf("Sem tempo medio de espera, nenhum cliente esteve na fila.\n\n");
  }

  return 0;
}
