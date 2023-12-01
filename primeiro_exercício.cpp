#include <iostream>

// Definição da classe do nó
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

// Definição da classe da lista duplamente encadeada
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Função para adicionar um elemento no final da lista
    void pushBack(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (!head)
        {
            // Se a lista estiver vazia, o novo nó é tanto a cabeça quanto a cauda
            head = tail = newNode;
        }
        else
        {
            // Se a lista não estiver vazia, adicionamos o novo nó ao final
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Função para imprimir a lista da frente para trás
    void printForward()
    {
        Node<T>* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Função para imprimir a lista de trás para frente
    void printBackward()
    {
        Node<T>* current = tail;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    bool verificaNos()
    {
        if (tail != nullptr && head != nullptr)
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
    // Exemplo de uso da lista encadeada dupla
    DoublyLinkedList<int> myList;
    int entrada = 1;
    while (entrada != 0) {
        entrada = menuInicial();

        switch (entrada) {
            case 1:
                if (myList.verificaNos()){
                    std::cout << ">> Lista está ocupada" << std::endl;
                }
                else
                {
                    std::cout << "Lista está vazia" << std::endl;
                }
                break;
            case 2:
                myList.pushBack(numeroEscolhido());
                break;
            default:
                std::cout << ">> Você não escolheu umas das opções" << std::endl;
        }
    }

    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);

    std::cout << "Lista da frente para trás: ";
    myList.printForward();

    std::cout << "Lista de trás para frente: ";
    myList.printBackward();

    return 0;
}