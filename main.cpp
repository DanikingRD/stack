#include <iostream>

using namespace std;

/*
 * ENUNCIADO: Stack
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1114116 - Jean Carlos Araujo Molina
 *              1116906 - Gabriel Mejía Acosta
 *              1114441 - Rafael Eduardo Peralta Pimentel
 *              1114814 - Hadelin Maria García Cedano
 *              1114950 - Elian Gabriel Villegas Báez
 *              1116614 - Luis Daniel de la Cruz García
 *              1116623 - Aquilenyi Suero de los Santos
 * FECHA: 05/08/2023 <== Fecha de realización
 */

struct Node
{
    Node *next;
    int value;
};

struct Stack
{
private:
    Node *top;
    uint len;

public:
    Stack()
    {
        top = nullptr;
        len = 0;
    }

    void push(int value)
    {
        // 1) Crear un nuevo nodo
        Node *newNode = new Node();
        // 2) Asignar el valor deseado
        newNode->value = value;
        // 3) Hacer que el nuevo nodo apunte al nodo siguiente.
        // El siguiente nodo será cualquier nodo que haya en el `TOP`
        // al momento de llamar esta funcion.
        newNode->next = this->top;
        // 4) Actualizar el nodo en el TOP.
        this->top = newNode;

        // 5) Incrementar su tamaño
        this->len++;
    }

    void pop()
    {
        if (len == 0)
            // What would happen if we pop() an empty stack?
            // segmentation fault
            return;

        // 1) Obtener el siguiente nodo en la pila.
        Node *nextInStack = this->top->next; // Tiene referencia al siguiente elemento del stack
        // 2) Eliminar el nodo actualmente en el TOP
        delete this->top; // borra la memoria de ese nodo
        // 3) Actualizar el nodo en el TOP.
        this->top = nextInStack;
        // Disminuir su tamaño
        this->len--;
    }

    /// @brief Regresa el valor más alto en la pila.
    int peek()
    {
        return this->top->value;
    }

    bool contains(int value)
    {
        Node *node = top;
        while (node != nullptr)
        {
            int nodeValue = node->value;
            if (nodeValue == value)
            {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    uint size() const
    {
        return this->len;
    }

    bool isEmpty() const
    {
        return this->len == 0;
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    string toString()
    {
        // 1) Title
        string result = "Stack contents (top to bottom):\n";
        // 2) Grab the next node in the stack
        Node *node = top;
        while (node != nullptr)
        {
            // Append each value
            result += to_string(node->value) + "\n";
            node = node->next; // Go to the next node
        }
        // 4) Print the stack size
        result += "\nStack size: " + to_string(size()) + "\n";
        return result;
    }
};

void testStack()
{
    Stack *stack = new Stack();

    // 1) Test push
    for (int val = 0; val < 10; val++)
    {
        stack->push(val);
    }
    // c++ 0, 1
    // 2) Test contains
    cout << "Contiene el valor 6 ? " << to_string(stack->contains(6)) << endl;

    cout << stack->toString() << endl;

    // 3) Test pop
    for (int i = 0; i < 5; i++)
    {
        stack->pop();
    }
    cout << stack->toString() << endl;
    cout << "Contiene el valor 6 ? " << to_string(stack->contains(6)) << endl;

    // 4) Test clear
    stack->clear();
    cout << "Se ha limpiado la pila" << endl;
    cout << stack->toString() << endl;
    delete stack;
}

void makePush(Stack *stack)
{
    cout << "";
    int value;
    cin >> value;
    stack->push(value);
    cout << "";
}

void makePop(Stack *stack)
{
    cout << "";
    stack->pop();
    cout << "";
}
void run()
{
    while (true)
    {
        Stack *stack = new Stack();
        int option;
        // Draw an intuitive menu
        cout << "Available options:\n"
             << "  1) Push\n"
             << "  2) Pop\n"
             << "  3) Peek\n"
             << "  4) Contains\n"
             << "  5) Size\n"
             << "  6) Clear\n"
             << "  7) Exit\n"
             << "Enter your choice: ";
        cin >> option;

        cout << endl;

        switch (option)
        {
        case 0:
            makePush(stack);
            break;

        case 1:
            makePop(stack);
            break;
        }
        delete stack;
    }
}

int main(int argc, char const *argv[])
{
    // Nodos
    testStack();
    run();
    return 0;
}
