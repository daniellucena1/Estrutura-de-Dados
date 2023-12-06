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
};

int menuInicial (int valor)

int main ()
{
    FilaUnica fila;



    return 0;
}