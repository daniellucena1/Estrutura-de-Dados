#include <iostream>

using namespace std;

template <typename T>
class No {
public:
    T numero;
    No<T>* proximo;
    No<T>* anterior;

    No(const T& entrada) : numero(entrada), proximo(nullptr), anterior(nullptr) {}
};

template <typename T>
class listaDupla {
private:
    No<T>* cabeca;
    No<T>* cauda;

public:
    listaDupla() : cabeca(nullptr), cauda(nullptr) {}

    bool addNumero(const T& entrada)
    {
        if (!cabeca)
        {
            No<T>* novoNo = new No<T>(entrada);

            cabeca = cauda = novoNo;
            return true;
        }

        No<T>* novoNo = new No<T>(entrada);

        No<T>* atual = cabeca;

        while(atual->proximo)
        {
            if (atual->numero < novoNo->numero && atual->proximo->numero > novoNo->numero)
            {
                novoNo->anterior = atual;
                novoNo->proximo = atual->proximo;
                atual->proximo->anterior = novoNo;
                atual->proximo = novoNo;
                return true;
            }
            atual = atual->proximo;
        }

        novoNo->anterior = cauda;
        cauda->proximo = novoNo;
        cauda = novoNo;
        return true;
    }

    bool removerNumero(const T& numero)
    {
        No<T>* atual = cabeca;

        while (atual)
        {
            if (atual->numero == numero)
            {
                if (atual->anterior)
                {
                    atual->anterior->proximo = atual->proximo;
                }
                else
                {
                    cabeca = atual->proximo;
                }

                if (atual->proximo)
                {
                    atual->proximo->anterior = atual->anterior;
                }
                else
                {
                    cauda = atual->anterior;
                }

                delete atual;
                return true;
            }

            atual = atual->proximo;
        }

        cout << "Número não encontrado na lista." << endl;
        return false;
    }

    void crescente()
    {
        No<T>* atual = cabeca;
        while (atual)
        {
            cout << atual->numero << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    void decrescente()
    {
        No<T>* atual = cauda;
        while (atual)
        {
            cout << atual->numero << " ";
            atual = atual->anterior;
        }
        cout << endl;
    }

    bool pesquisar(const T& entrada)
    {
        No<T>* atual = cabeca;

        while(atual)
        {
            if (atual->numero == entrada)
            {
                cout << ">> Número encontrado" << endl;
                return true;
            }
            atual = atual->proximo;
        }
        cout << ">> Número não encontrado" << endl;
        return false;
    }

    bool verificaNos()
    {
        if (cabeca != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int menuInicial()
{
    int entrada;
    cout << ">> 1. Verificar itens da lista" << endl;
    cout << ">> 2. Inserir numeros" << endl;
    cout << ">> 3. Remover numeros" << endl;
    cout << ">> 4. Pesquisar numero" << endl;
    cout << ">> 5. Mostrar numeros em ordem crescente" << endl;
    cout << ">> 6. Mostrar numeros em forma decrescente" << endl;
    cout << ">> 0. Encerrar" << endl;
    cout << "Escolha umas das opcoes: ";
    cin >> entrada;
    return entrada;
}

int numeroEscolhido() {
    int num;
    cout << ">> Digite um numero: ";
    cin >> num;
    return num;
}

int main()
{
    listaDupla<int> lista;

    int entrada = 1;

    while (entrada != 0)
    {
        entrada = menuInicial();

        switch (entrada)
        {
            case 1:
                if (lista.verificaNos())
                {
                    cout << ">> Lista esta ocupada" << endl;
                }
                else
                {
                    cout << "Lista esta vazia" << endl;
                }
                break;
            case 2:
                lista.addNumero(numeroEscolhido());
                break;
            case 3:
                lista.removerNumero(numeroEscolhido());
                break;
            case 4:
                lista.pesquisar(numeroEscolhido());
                break;
            case 5:
                lista.crescente();
                break;
            case 6:
                lista.decrescente();
                break;
            default:
                cout << ">> Encerrando..." << endl;
        }
    }
    return 0;
}