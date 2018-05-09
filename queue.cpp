#include <iostream>
using namespace std;

class Queue
{
private:
    int* front;
    int* rear;
    bool _isEmpty;
public:
    Queue();
    void enQueue(int value);
    void deQueue();
    int getFront();
    int getRear();
    bool isEmpty();
    unsigned int getSize();
    void print();
    ~Queue();
};

int main()
{
    Queue myQueue;
    for (int i = 0; i < 0; i++)
    {
        myQueue.enQueue(i);
    }
    cout << myQueue.getSize() << endl;
    //myQueue.deQueue();
    myQueue.print();
    return 0;
}

Queue::Queue()
{
    rear = new int;
    front = rear;
    _isEmpty = true;
}

void Queue::enQueue(int value)
{
    if (_isEmpty)
    {
        *front = value;
        *rear = value;
        _isEmpty = false;
    }
    else
    {
        *(++rear) = value;
    }
}

void Queue::deQueue()
{
    front++;
}

int Queue::getFront()
{
    return *front;
}

int Queue::getRear()
{
    return *rear;
}

bool Queue::isEmpty()
{
    return (front == rear);
}

unsigned int Queue::getSize()
{
    unsigned int size;
    if (_isEmpty)
    {
        size = 0;
    }
    else
    {
        size = rear - front + 1;
    }
    return size;
}

void Queue::print()
{
    int* tmpPtr = front;
    if (!_isEmpty)
    {
        while (tmpPtr != rear)
        {
            cout << *(tmpPtr++) << " ";
        }
        cout << *(tmpPtr++);
    }
    delete tmpPtr;
}

Queue::~Queue()
{
    delete front;
    delete rear;
}
