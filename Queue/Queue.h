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

    Queue& Push(T Data)
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

    T Front() const
    {
        if(Empty()) 
        {
            cout << "Empty Queue" << '\n';
            return NULL;
        }
        return Head->Data;
    }

    T Back() const
    {
        if(Empty()) 
        {
            cout << "Empty Queue" << '\n';
            return NULL;
        }
        return Tail->Data;
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
    Q.Push(1).Push(2).Push(3);
    Q.Push(0).Push(-1).Push(-2);
    Q.PopFront();
    Q.PopBack();
    Q.Print();
    cout << Q.Size() << '\n';
}

template <typename T>
class Deque
{
public:
    Deque() : Head(nullptr), Tail(nullptr), Length(0) { }

    Deque& PushFront(T Data)
    {
        Node<T>* NewNode = new Node(Data);

        if(!Head)
        {
            Head = Tail = NewNode;
        }
        else
        {
            Head->Prev = NewNode;
            NewNode->Next = Head;
            Head = NewNode;
        }

        Length++;
        return *this;
    }

    Deque& PushBack(T Data)
    {
        Node<T>* NewNode = new Node(Data);
        
        if(!Head)
        {
            Head = Tail = NewNode;
        }
        else
        {
            Tail->Next = NewNode;
            NewNode->Prev = Tail;
            Tail = NewNode;
        }

        Length++;
        return *this;
    }

    Deque& PopFront()
    {
        Node<T>* TempNode = Head;
        Head = Head->Next;
        Head->Prev = nullptr;
        delete TempNode;
        Length--;
        return *this;
    }

    Deque& PopBack()
    {
        Node<T>* TempNode = Tail;
        Tail = Tail->Prev;
        Tail->Next = nullptr;
        delete TempNode;
        Length--;
        return *this;
    }

    T& operator[](size_t Index)
    {
        Node<T>* TempNode = Head;
        for(int i = 0; i < Index; ++i)
        {
            TempNode = TempNode->Next;
        }
        return TempNode->Data;
    }

    T& At(size_t Index)
    {
        if(Index < 0 || Index > Length - 1)
        {
            throw out_of_range("Index Out Of Bounds");
        } 

        Node<T>* TempNode = Head;
        for(int i = 0; i < Index; ++i)
        {
            TempNode = TempNode->Next;
        }
        return TempNode->Data;
    }

    const T& Front() const
    {
        return Head->Data;
    }

    const T& Back() const
    {
        return Tail->Data;
    }

    int Size() const
    {
        return Length;
    }

    bool Empty() const
    {
        if(!Head) return true;
        return false;
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

void Deque_Test()
{
    cout << "------------- Deque Test -------------" << '\n';
    Deque<int> Dq;
    Dq.PushBack(1).PushBack(2).PushBack(3);
    Dq.PushFront(0).PushFront(-1).PushFront(-2);
    Dq.Print();
    cout << "[] 를 통한 2번째 인덱스의 값: " << Dq[2] << '\n';
    cout << "At 을 통한 3번째 인덱스의 값: " << Dq.At(3) << '\n';

    Dq.PopBack().PopFront();
    Dq.Print();
    cout << "--- PopBack, PopFront 실행 후 값 ---" << '\n';
    cout << "[] 를 통한 2번째 인덱스의 값: " << Dq[2] << '\n';
    cout << "At 을 통한 3번째 인덱스의 값: " << Dq.At(3) << '\n';
}

}