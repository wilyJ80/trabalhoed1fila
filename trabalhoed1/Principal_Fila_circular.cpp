#include "tad_fila_estatica_circular.h"
#include <stdio.h>

int main() {

  T_Fila fila;
  T_Item item;

  iniciarFila(&fila);

  char resp;

  printf("Digite\n (i)para inserir na fila \n (r)para remover na fila? \n "
         "(s)para sair \n");
  scanf(" %c", &resp);

  while (resp == 'i' || resp == 'r') {
    if (resp == 'i') {
      printf("Informe o item : ");
      scanf("%d", &item.campo);

      int resultado = inserir(&fila, item);
      if (resultado == 1)
        printf("Item inserido com sucesso \n");
      else
        printf("Erro ao inserir o Item \n");

      printf("\n inicio = %d ; fim = %d ; FILA : ", fila.inicio, fila.fim);
      exibir(&fila);
      printf("\n");
      printf("VETOR COMPLETO : ");
      exibirCompleto(&fila);

      printf("\n\n");
    }

    if (resp == 'r') {
      int resultado = remover(&fila);
      if (resultado == 1)
        printf("Item removido com sucesso \n");
      else
        printf("Erro ao remover o Item \n");

      printf("\n inicio = %d ; fim = %d ; FILA : ", fila.inicio, fila.fim);
      exibir(&fila);
      printf("\n");
      printf("VETOR COMPLETO : ");
      exibirCompleto(&fila);

      printf("\n\n");
    }

    printf("Digite\n (i)para inserir na fila \n (r)para remover na fila? \n "
           "(s)para sair \n");
    scanf(" %c", &resp);
  }
}
