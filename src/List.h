#include <iostream>
using namespace std;

namespace list
{

template<typename T>
struct SingleNode
{
public:
    SingleNode(T InData) : Data(InData), Next(nullptr) { }

    T Data;
    SingleNode* Next;
};

template<typename T>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : Head(nullptr), Length(0) {}

    SinglyLinkedList& PushBack(T Data)
    {
        SingleNode<T>* NewNode = new SingleNode(Data);
        if(!Head)
        {
            Head = NewNode;
            Length++;
            return *this;
        }

        SingleNode<T>* TempNode = Head;
        while(TempNode->Next)
        {
            TempNode = TempNode->Next;
        }
        TempNode->Next = NewNode;
        Length++;
        return *this;
    }

    SinglyLinkedList& Insert(T Loc, T Data)
    {
        SingleNode<T>* NewNode = new SingleNode(Data);
        if(!Head)
        {
            Head = NewNode;
            Length++;
            return *this;
        }

        SingleNode<T>* TempNode = Head;
        while(TempNode)
        {
            if(TempNode->Data == Loc)
            {
                NewNode->Next = Head;
                Head = NewNode;
                Length++;
                return *this;
            }
            else if(TempNode->Next->Data == Loc)
            {
                NewNode->Next = TempNode->Next;
                TempNode->Next = NewNode;
                Length++;
                return *this;
            }
            
            TempNode = TempNode->Next;
        }
        return *this;
    }

    SinglyLinkedList& Erase(T Loc)
    {
        SingleNode<T>* TempNode = Head;
        while(TempNode)
        {
            if(TempNode->Data == Loc)
            {
                Head = TempNode->Next;
                delete TempNode;
                Length--;
                return *this;
            }
            else if(TempNode->Next->Data == Loc)
            {
                SingleNode<T>* Temp = TempNode->Next;
                TempNode->Next = TempNode->Next->Next;
                delete Temp;
                Length--;
                return *this;
            }
            TempNode = TempNode->Next;
        }
        return *this;
    }

    bool Search(T Loc)
    {
        SingleNode<T>* Temp = Head;
        while(Temp->Next)
        {
            if(Temp->Data == Loc) return true;
            Temp = Temp->Next;
        }
        return false;
    }
    
    void Print() const
    {
        SingleNode<T>* Temp = Head;
        while(Temp)
        {
            cout << Temp->Data << ' ';
            Temp = Temp->Next;
        }
        Temp = nullptr;
    }

    int Size() const
    {
        return Length;
    }

private:
    SingleNode<T>* Head;
    int Length;
};

template <typename T>
struct DoubleNode
{
public:
    DoubleNode(T InData) : Data(InData), Next(nullptr), Prev(nullptr) { }

    T Data;
    DoubleNode* Next;
    DoubleNode* Prev;
};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : Head(nullptr), Length(0) { }

    DoublyLinkedList& PushBack(T Data)
    {
        DoubleNode<T>* NewNode = new DoubleNode(Data);

        if(!Head)
        {
            Head = NewNode;
            Length++;
            return *this;
        }

        DoubleNode<T>* TempNode = Head;
        while(TempNode->Next)
        {
            TempNode = TempNode->Next;
        }
        TempNode->Next = NewNode;
        NewNode->Prev = TempNode;
        Length++;
        return *this;
    }

    DoublyLinkedList& Insert(T Loc, T Data)
    {
        DoubleNode<T>* NewNode = new DoubleNode(Data);

        if(!Head)
        {
            Head = NewNode;
            Length++;
            return *this;
        }

        DoubleNode<T>* TempNode = Head;
        while (TempNode)
        {
            if (TempNode->Data == Loc)
            {
                if (TempNode == Head)
                {
                    NewNode->Next = Head;
                    Head->Prev = NewNode;
                    Head = NewNode;
                }
                else
                {
                    NewNode->Next = TempNode;
                    NewNode->Prev = TempNode->Prev;
                    TempNode->Prev->Next = NewNode;
                    TempNode->Prev = NewNode;
                }
                Length++;
                return *this;
            }

            TempNode = TempNode->Next;
        }
        return *this;
    }

    DoublyLinkedList& Erase(T Loc)
    {
        DoubleNode<T>* TempNode = Head;
        while(TempNode)
        {
            if(TempNode->Data == Loc)
            {
                Head = Head->Next;
                delete TempNode;
                Length--;
                return *this;
            }
            else if(TempNode->Next && TempNode->Next->Data == Loc)
            {
                DoubleNode<T>* Temp = TempNode->Next;
                TempNode->Next = TempNode->Next->Next;
                TempNode->Next->Prev = TempNode;
                delete Temp;
                Length--;
                return *this;
            }
            TempNode = TempNode->Next;
        }
        return *this;
    }

    bool Search(T Loc) const
    {
        DoubleNode<T>* TempNode = Head;
        while(TempNode)
        {
            if(TempNode->Data == Loc) return true;
            TempNode = TempNode->Next;
        }
        return *this;
    }

    int Size() const
    {
        return Length;
    }

    void Print() const
    {
        DoubleNode<T>* TempNode = Head;
        while(TempNode)
        {
            cout << TempNode->Data << ' ';
            TempNode = TempNode->Next;
        }
        TempNode = nullptr;
    }

private:
    DoubleNode<T>* Head;
    int Length;
};

void SinglyLinkedList_Test()
{
    cout << "------------- SinglyLinkedList Test -------------" << '\n';
    SinglyLinkedList<int> SLL;
    SLL.PushBack(1).PushBack(2).PushBack(3);
    SLL.Insert(1, 100);
    SLL.Insert(2, 150);
    SLL.Insert(3, 200);
    SLL.Erase(150);
    SLL.Erase(100);
    SLL.Print();
    cout << '\n' << SLL.Size() << '\n';
}

void DoublyLinkedList_Test()
{
    cout << "------------- DoublyLinkedList Test -------------" << '\n';
    DoublyLinkedList<int> DLL;
    DLL.PushBack(1).PushBack(2).PushBack(3);
    DLL.Insert(1, 100);
    DLL.Insert(2, 150);
    DLL.Insert(3, 200);
    DLL.Erase(150);
    DLL.Erase(100);
    DLL.Print();
    cout << '\n' << DLL.Size() << '\n';
}
}