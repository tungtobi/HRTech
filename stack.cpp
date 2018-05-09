#include <iostream>
using namespace std;

class Stack
{
private:
    int* top;
    unsigned int size;
public:
    Stack();
    void push(int value);
    void pop();
    int getTop();
    bool isEmpty();
    unsigned int getSize();
    void print();
    ~Stack();
};

int main()
{
    Stack myStack;
    //for (int i = 0; i <= 10; i++)
    {
        myStack.push(0);
    }
    //myStack.pop();
    myStack.print();
    return 0;
}

Stack::Stack()
{
    top = new int;
    size = 0;
}

void Stack::push(int value)
{
    if (isEmpty())
    {
		*top = value;
    }
    else
    {
        *(++top) = value;
    }
    size++;
}

void Stack::pop()
{
    top--;
    size--;
}

int Stack::getTop()
{
    return *top;
}

bool Stack::isEmpty()
{
    return (size == 0);
}

unsigned int Stack::getSize()
{
    return size;
}

void Stack::print()
{
    int* tmpPtr = top;
    for (int i = 0; i < size; i++)
    {
        cout << *(tmpPtr--) << " ";
    }
    delete tmpPtr;
}

Stack::~Stack()
{
    delete top;
}
