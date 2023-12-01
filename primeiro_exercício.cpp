#include <iostream>

template <typename T>
class No {
public:
    T numero;
    No<T>* proximo;
    No<T>* anterior;

    No(const T& value) : numero(value), proximo(nullptr), anterior(nullptr) {}
};

template <typename T>
class listaDupla {
private:
    No<T>* cabeca;
    No<T>* cauda;

public:
    listaDupla() : cabeca(nullptr), cauda(nullptr) {}

    void addNumero(const T& value)
    {
        No<T>* newNode = new No<T>(value);

        if (!cabeca)
        {
            cabeca = cauda = newNode;
        }
        else
        {
            newNode->anterior = cauda;
            cauda->proximo = newNode;
            cauda = newNode;
        }
    }
    void crescente()
    {
        No<T>* current = cabeca;
        while (current)
        {
            std::cout << current->numero << " ";
            current = current->proximo;
        }
        std::cout << std::endl;
    }
    void decrescente()
    {
        No<T>* current = cauda;
        while (current)
        {
            std::cout << current->numero << " ";
            current = current->anterior;
        }
        std::cout << std::endl;
    }

    bool verificaNos()
    {
        if (cauda != nullptr && cabeca != nullptr)
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
    int entrada = 0;
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
    while (entrada != 0) {
        entrada = menuInicial();

        switch (entrada) {
            case 1:
                if (lista.verificaNos()){
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
            default:
                std::cout << ">> Você não escolheu umas das opções" << std::endl;
        }
    }

    lista.addNumero(1);
    lista.addNumero(2);
    lista.addNumero(3);

    std::cout << "Lista da frente para trás: ";
    lista.crescente();

    std::cout << "Lista de trás para frente: ";
    lista.decrescente();

    return 0;
}