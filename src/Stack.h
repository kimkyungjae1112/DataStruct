#include <iostream>
using namespace std;

namespace stack
{
template <typename T>
struct Node
{
public:
    Node(T InData) : Data(InData), Next(nullptr) {}

    Node* Next;
    T Data;
};

template <typename T>
class Stack
{
public:
    Stack() : Head(nullptr), Length(0) {}

    Stack& Push(T Data)
    {
        Node<T>* NewNode = new Node(Data);
        NewNode->Next = Head;
        Head = NewNode; 
        Length++;
        return *this;
    }

    Stack& Pop()
    {
        if(!Head) 
        {
            cout << "Empty Stack" << '\n';
            return *this;
        }
        Node<T>* TempNode = Head;
        Head = Head->Next;
        delete TempNode; 
        Length--;
        return *this;
    }

    T Top() const
    {
         if(!Head) 
        {
            cout << "Empty Stack" << '\n';
            return -1;
        }
        return Head->Data;
    }

    bool Empty() const
    {
        if(Head) return false;
        return true;
    }

    int Size() const
    {
        return Length;
    }

    void Print()
    {
        while(!Empty())
        {
            cout << Top() << ' ';
            Pop();
        }
        cout << '\n';
    }

private:
    Node<T>* Head;
    int Length;
};

void Stack_Test()
{
    cout << "------------- Stack Test -------------" << '\n';
    Stack<int> S;
    S.Push(1).Push(4).Push(8);
    S.Pop();
    S.Push(123);
    cout << S.Size() << '\n';
    S.Print();
}
}