#include <iostream>

using namespace std;

typedef struct No
{
    int dado;
    No* proximo;
} No;

class FilaUnica
{
    private:
        No* inicio;
        No* fim;
    public:
        FilaUnica() : inicio(nullptr), fim (nullptr) {}

        bool estaVazia()
        {
            return (inicio == nullptr);
        }

        void enfileirar (int valor)
        {
            No* novoNo = new No{valor, nullptr};

            if (estaVazia())
            {
                inicio = fim = novoNo;
            }
            else
            {
                fim->proximo = novoNo;
                fim = novoNo;
            }
        }

        void desenfileirar ()
        {
            if (estaVazia())
            {
                cout << "A fila esta vazia, nao e possivel realizar o desenfileramento" << endl;
            }
            else
            {
                int valor = inicio->dado;
                No* novoNo = inicio;

                if (inicio == fim)
                {
                    inicio = fim = nullptr;
                }
                else
                {
                    inicio = inicio->proximo;
                }

                delete novoNo;
                cout << ">> Valor retirado: " << endl;
                cout << "-> " << valor << endl;
            }
        }

        void mostrarValores ()
        {
            if (estaVazia())
            {
                cout << "A fila esta vazia nao ha elementos para mostrar" << endl;
            }
            else
            {
                No* atual = inicio;
                cout << ">> Numeros na fila: " << endl;
                while (atual)
                {
                    cout << "-> " << atual->dado << endl;
                    atual = atual->proximo;
                }
            }
        }

    int liberarNos()
    {
        int cont = 0;
        while (inicio != nullptr) {
            No* temp = inicio;
            inicio = inicio->proximo;
            delete temp;
            cont += 1;
        }

        fim = nullptr;
        return cont;
    }
};

int menuInicial ()
{
    int entrada;
    cout << ">> 1 - Verificar se a lista esta vazia" << endl;
    cout << ">> 2 - Enfileirar" << endl;
    cout << ">> 3 - Desenfileirar" << endl;
    cout << ">> 4 - Imprimir fila" << endl;
    cout << ">> 0 - Encerrar" << endl;
    cout << ">> Digite uma opcao: " << endl << "-> ";
    cin >> entrada;
    return entrada;
}

int numeroEscolhido()
{
    int entrada;
    cout << ">> Escolha um numero para a fila :" << endl << "-> ";
    cin >> entrada;
    return entrada;
}

int main ()
{
    FilaUnica fila;
    int entrada = -1;

    while (entrada != 0)
    {
        entrada = menuInicial();

        switch (entrada)
        {
            case 1:
                if (fila.estaVazia())
                {
                    cout << ">> Lista esta vazia" << endl;
                }
                else
                {
                    cout << ">> A lista esta ocupada" << endl;
                }
                break;
            case 2:
                fila.enfileirar(numeroEscolhido());
                break;
            case 3:
                fila.desenfileirar();
                break;
            case 4:
                fila.mostrarValores();
                break;
            default:
                cout << ">> Encerrando..." << endl;
        }
    }

    cout << "-> Nos liberados: " << fila.liberarNos();
    return 0;
}