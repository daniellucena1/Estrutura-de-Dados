#include <iostream>

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

        std::cout << "Número não encontrado na lista." << std::endl;
        return false;
    }

    void crescente()
    {
        No<T>* atual = cabeca;
        while (atual)
        {
            std::cout << atual->numero << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    void decrescente()
    {
        No<T>* atual = cauda;
        while (atual)
        {
            std::cout << atual->numero << " ";
            atual = atual->anterior;
        }
        std::cout << std::endl;
    }

    bool pesquisar(const T& entrada)
    {
        No<T>* atual = cabeca;

        while(atual)
        {
            if (atual->numero == entrada)
            {
                std::cout << ">> Número encontrado" << std::endl;
                return true;
            }
            atual = atual->proximo;
        }
        std::cout << ">> Número não encontrado" << std::endl;
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
    std::cout << ">> 1. Verificar itens da lista" << std::endl;
    std::cout << ">> 2. Inserir números" << std::endl;
    std::cout << ">> 3. Remover números" << std::endl;
    std::cout << ">> 4. Pesquisar número" << std::endl;
    std::cout << ">> 5. Mostrar números em ordem crescente" << std::endl;
    std::cout << ">> 6. Mostrar números em forma decrescente" << std::endl;
    std::cout << ">> 0. Encerrar" << std::endl;
    std::cout << "Escolha umas das opções: ";
    std::cin >> entrada;
    return entrada;
}

int numeroEscolhido() {
    int num;
    std::cout << ">> Digite um número: ";
    std::cin >> num;
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
                    std::cout << ">> Lista está ocupada" << std::endl;
                }
                else
                {
                    std::cout << "Lista está vazia" << std::endl;
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
                std::cout << ">> Encerrando..." << std::endl;
        }
    }

    std::cout << "Lista da frente para trás: ";
    lista.crescente();

    std::cout << "Lista de trás para frente: ";
    lista.decrescente();

    return 0;
}