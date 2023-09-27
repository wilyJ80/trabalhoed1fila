#include <stdio.h>

int const max = 5;

struct T_Item
{
	int campo;
};

struct T_Fila
{
	int inicio;
	int fim;
	int qtdeAtual;
	T_Item dados[max];
};

void iniciarFila(T_Fila *fila)
{
	(*fila).inicio = 1;
	(*fila).fim = (*fila).inicio;
	(*fila).qtdeAtual = 0;
}

int chkFilaVazia(T_Fila *fila)
{
	return (*fila).qtdeAtual == 0;
}

int chkFilaCheia(T_Fila *fila)
{
	return (*fila).qtdeAtual == max-1;
}

void ajustarIndice(T_Fila *fila, char opcao)
{
	if (opcao == 'F')
	{
   	   (*fila).fim = (*fila).fim + 1;
   	   if ((*fila).fim > max-1) 
		  (*fila).fim = 1;  
	}

	if (opcao == 'I')
	{
   	   (*fila).inicio = (*fila).inicio + 1;
   	   if ((*fila).inicio > max-1) 
		  (*fila).inicio = 1;  
	}
	
}

int inserir(T_Fila *fila, T_Item item)
{
	int flag = 0;
	
	if (  chkFilaCheia(fila)   )
		flag = 0;
	else	
	{
		(*fila).dados[(*fila).fim] = item;
		ajustarIndice(fila, 'F');
		(*fila).qtdeAtual++;
		flag = 1;
	}
		
	return flag;	
}


int remover(T_Fila *fila)
{
	int flag;
	
	if (chkFilaVazia(fila) )
		flag = 0;
	else
	{
		ajustarIndice(fila, 'I');
		(*fila).qtdeAtual--;
		
		flag = 1;
	}
	
	return flag;
}


void exibir(T_Fila *fila)
{
	int cont = 0;
	int i = (*fila).inicio;

	while (cont < (*fila).qtdeAtual)
	{
		printf(" %d ",(*fila).dados[i].campo);
		i++;
		cont++;
		
		if (i == max) i = 1;
	}

}

void exibirCompleto(T_Fila *fila)
{
	for (int i = 0; i < max; i++)
		printf(" %d ",(*fila).dados[i].campo);
}