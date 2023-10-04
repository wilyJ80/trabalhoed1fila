/*
 * ATENCAO: ESTOU CONSIDERANDO O CLIENTE COMO PESSOA QUE
 * ENTROU NA FILA. QUEM NAO ENTROU NA FILA NAO E CLIENTE
 */

#include "rotinas.h"
#include "tad_fila_estatica_circular.h"
#include <stdio.h>

#define FINAL 100

int espera, totcli, client;
int caixa[3] = {0, 0, 0};
struct T_Fila fila;
struct T_Item crono;

int main(void) {

  srand((unsigned)time(NULL));

  espera = 0, totcli = 0;
  crono.campo = 0;
  int naoatendidos = 0;
  int naochegaram = 0;

  iniciarFila(&fila);

  printf("INICIO (CRONOMETRO 0)\n");
  while (crono.campo < FINAL) {

    // teste
    printf("\nFILA: ");
    exibir(&fila);
    printf("\n");

    if (ClienteChegou()) {

      int entrouNaFila = inserir(&fila, crono);

      // teste
      if (entrouNaFila) {
        printf("Cliente entrou na fila.\n");
        totcli++;

      } else {
        printf("Fila cheia, pessoa nao pode entrar.\n");
        naoatendidos++;
      }
      printf("FILA: ");
      exibir(&fila);
      printf("\n");

    } else {
      naochegaram++;
    }

    for (int i = 0; i < 3; i++) {

      if (!chkFilaVazia(&fila) && caixa[i] == 0) {

        client = remover(&fila);

        // teste
        printf("Cliente saiu da fila e entrou no caixa.\n");
        printf("FILA: ");
        exibir(&fila);
        printf("\n");

        espera += (crono.campo - client);

        caixa[i] = Transacao();
      }
    }

    printf("CAIXA: ");
    for (int i = 0; i < 3; i++) {

      if (caixa[i] != 0) {
        printf("%d ", caixa[i]);
        caixa[i]--;
      }
    }

    crono.campo++;
    printf("\n\n************************\nCRONOMETRO: %d\n", crono.campo);
  }

  printf("\n");
  printf("Tempo de atendimento: %d\n", FINAL);
  printf("Total de clientes: %d\n", totcli);
  printf("Tempo total de espera: %d\n", espera);
  printf("Pessoas nao atendidas: %d\n", naoatendidos);
  printf("Nao chegaram: %d\n", naochegaram);

  if (totcli > 0) {
    double tempomedioespera = ((double)espera / totcli);
    printf("Tempo medio de espera: %f\n\n", tempomedioespera);

  } else {

    printf("Sem tempo medio de espera, nenhum cliente esteve na fila.\n\n");
  }

  return 0;
}
