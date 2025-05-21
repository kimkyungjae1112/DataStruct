#include <iostream>
using namespace std;

namespace queue
{

template <typename T>
struct Node
{
public:
    Node(T InData) : Data(InData), Next(nullptr), Prev(nullptr) { }

    Node* Next;
    Node* Prev;
    T Data;
};

template <typename T>
class Queue
{
public:
    Queue() : Head(nullptr), Tail(nullptr), Length(0) { }

    Queue& PushFront(T Data)
    {
        Node<T>* NewNode = new Node(Data);

        if(!Head)
        {
            Head = Tail = NewNode;
        }
        else
        {
            NewNode->Next = Head;
            Head->Prev = NewNode;
            Head = NewNode;
        }
        Length++;
        return *this;
    }

    Queue& PushBack(T Data)
    {
        Node<T>* NewNode = new Node(Data);

        if(!Head)
        {
            Head = Tail = NewNode;
        }
        else
        {
            NewNode->Prev = Tail;
            Tail->Next = NewNode;
            Tail = NewNode;
        }
        Length++;
        return *this;
    }
    
    Queue& PopFront()
    {
        if(Empty())
        {
            cout << "Empty Queue" << '\n';
            return *this;
        }
        
        Node<T>* TempNode = Head;
        Head = Head->Next;
        Head->Prev = nullptr;
        delete TempNode;
        Length--;
        return *this;
    }

    Queue& PopBack()
    {
        if(Empty())
        {
            cout << "Empty Queue" << '\n';
            return *this;
        }
        
        Node<T>* TempNode = Tail;
        Tail = Tail->Prev;
        Tail->Next = nullptr;
        delete TempNode;
        Length--;
        return *this;
    }

    T Top() const
    {
        if(Empty()) 
        {
            cout << "Empty Queue" << '\n';
            return NULL;
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

    void Print() const
    {
        Node<T>* TempNode = Head;
        while(TempNode)
        {
            cout << TempNode->Data << ' ';
            TempNode = TempNode->Next;
        }
        cout << '\n';
    }

private:
    Node<T>* Head;
    Node<T>* Tail;
    int Length;
};

void Queue_Test()
{
    cout << "------------- Queue Test -------------" << '\n';
    Queue<int> Q;
    Q.PushBack(1).PushBack(2).PushBack(3);
    Q.PushFront(0).PushFront(-1).PushFront(-2);
    Q.PopFront();
    Q.PopBack();
    Q.Print();
    cout << Q.Size() << '\n';
}
}