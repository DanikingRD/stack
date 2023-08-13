#include <iostream>

using namespace std;

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

        // 5) Incrementar el length tracker
        this->len++;

        // TODO: What would happen if we push() a nullptr?
    }

    void pop()
    {
        // 1) Obtener el siguiente nodo en la pila.
        Node *nextInStack = this->top->next;
        // 2) Eliminar el nodo actualmente en el TOP
        delete this->top;
        // 3) Actualizar el nodo en el TOP.
        this->top = nextInStack;
        // Disminuye el length tracker
        this->len--;

        // TODO: What would happen if we pop() an empty stack?
        // TODO: It could be useful to return the value of the popped node.
    }

    /// @brief Regresa el valor más alto en la pila.
    int peek()
    {
        return this->top->value;
    }

    bool contains(int value)
    {
        // TODO: PUEDE MEJORAR UTILIZANDO UN BINARY SEARCH.
        Node *node = top;
        while (node != nullptr)
        {
            // linear search
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

    string toString()
    {
        // 1) Title
        string result = "Stack contents (top to bottom):\n";
        // 2) Grab the next node in the stack
        Node *node = top;
        while (node != nullptr)
        {
            // Append each value
            result += to_string(node->value) + " ";
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

    for (int val = 0; val < 10; val++)
    {
        stack->push(val);
    }

    cout << "Contiene el valor 6 ? " << to_string(stack->contains(6)) << endl;

    cout << stack->toString() << endl;

    for (int i = 0; i < 5; i++)

    {
        stack->pop();
    }
    cout << stack->toString() << endl;
    cout << "Contiene el valor 6 ? " << to_string(stack->contains(6)) << endl;

    delete stack;
}
int main(int argc, char const *argv[])
{
    testStack();
    // TODO: Implement the whole program here.
    return 0;
}
