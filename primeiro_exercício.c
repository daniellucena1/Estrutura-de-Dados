#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
    struct No *anterior;

No;

typedef struct listaDupla
{
    No *cabeca;
    No *cauda;
}
listaDupla;

void Inicialzar(listaDupla* lista)
{
    lista->cabeca = NULL;
    lista->cauda = NULL;
}

void AddNoFinal(listaDupla* lista, int valor)
{
    No* novoNo = (No*) malloc(sizeof(No));

    if(!novoNo)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    novoNo->dado = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if(!lista->cabeca)
    {
        lista->cabeca = lista->cauda = novoNo;
    }
    else
    {
        novoNo->anterior = lista->cauda;
        lista->cauda->proximo = novoNo;
        lista->cauda = novoNo;
    }
}

void FrenteParaTas(const listaDupla* lista)
{
    No* atual = lista->cabeca;
    do
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    while(atual);
    printf("\n");
}

void TrasParaFrente(const listaDupla* lista)
{
    No* atual = lista->cauda;
    do
    {
        printf("%d ", atual->dado);
        atual = atual->anterior;
    }
    while(atual);
    printf("\n");
}

void LiberarLista(listaDupla* lista)
{
    No* atual = lista->cabeca;
    No* proximo;
    do
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    while(atual);
    lista->cabeca = lista->cauda = NULL;
}

int MenuInicial()
{
    int entrada = 0;
    printf(">> Verificar se a lista está vazia");
    printf(">> Adicionar números");
    printf(">> Remover números");
    printf(">> ");
    printf(">> ");
    printf(">> Escolha uma das opções:\n");
    scanf("%d", &entrada);
    scanf(stdin);
    return entrada;
}

int main()
{
    listaDupla lista;
    Inicialzar(&lista);

    int entrada = 1;

    while(entrada != 0)
    {
        entrada = MenuInicial();

        switch (entrada)
        {
            case 1:
                if(lista.cabeca == NULL)
                {
                    printf(">> A lista está vazia\n");
                }
                else
                {
                    printf(">> A lista está ocupada\n");
                }
                break;
        }
    }

    AddNoFinal(&lista, 1);
    AddNoFinal(&lista, 2);
    AddNoFinal(&lista, 3);

    printf("Lista de frente para trás: ");
    FrenteParaTas(&lista);

    printf("Lista de trás para frente: ");
    TrasParaFrente(&lista);

    LiberarLista(&lista);

    return 0;
}