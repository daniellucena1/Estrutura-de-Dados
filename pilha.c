#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
  int data;
  struct Stack *next;
} Stack;

Stack criaPilha(int novo)
{
  Stack *topo = malloc(sizeof(Stack));
  topo->data = novo;
  topo->next = NULL;
  return *topo;
}

int verificarVazio(Stack *topo)
{
  if (topo == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void imprimirPilha(Stack *topo)
{
  Stack *topoAtual = topo;

  while (topoAtual != NULL)
  {
    printf("%d \n", topoAtual->data);
    topoAtual = topoAtual->next;
  }
}

Stack *push(Stack *topo, int novo)
{
  Stack *novoTopo = malloc(sizeof(Stack));

  if (novoTopo == NULL)
    return topo;

  novoTopo->data = novo;
  novoTopo->next = topo;

  return novoTopo;
}

Stack *pop(Stack *topo)
{
  Stack *novoTopo = malloc(sizeof(Stack));

  if (novoTopo == NULL)
    return topo;

  novoTopo = topo->next;
  free(topo);
  return novoTopo;
}

int liberarNos(Stack* topo)
{
    int cont = 0;
    while(topo != NULL)
    {
        Stack* temp = topo;
        topo = topo->next;
        free(temp);
        cont += 1;
    }
    return cont;
}

int main()
{
  int opcao = -1;
  Stack *pilha = NULL;

  while (opcao != 0)
  {
    printf(">> Digite: \n 1 - Empilhar \n 2 - Desempilhar \n 3 - Imprimir Pilha \n 0 - Sair \n -> ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      int novo;
      printf("Qual item deseja empilhar: ");
      scanf("%d", &novo);
      pilha = push(pilha, novo);
      break;
    case 2:
      pilha = pop(pilha);
      break;
    case 3:
      printf("Imprimindo...\n");
      imprimirPilha(pilha);
    case 0:
      break;
    }
  }
  printf("-> Nos liberados: %d", liberarNos(pilha));
}