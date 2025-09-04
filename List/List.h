#include <iostream>
using namespace std;

namespace list_my
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

template<typename T>
struct Node
{
public:
	Node(T InData) : Data(InData), Next(nullptr), Prev(nullptr) {}

	T Data;
	Node* Next;
	Node* Prev;
};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : Head(nullptr), Tail(nullptr), Length(0) {}

    DoublyLinkedList& PushBack(T Data)
    {
        Node<T>* NewNode = new Node(Data);

        if (Head == nullptr)
        {
            Head = Tail = NewNode;
        }
        else
        {
            NewNode->Prev = Tail;
            NewNode->Next = nullptr;
            Tail->Next = NewNode;
            Tail = NewNode;
        }

        Length++;
        return *this;
    }

    DoublyLinkedList& PushFront(T Data)
    {
	Node<T>* NewNode = new Node(Data);

	if (Head == nullptr)
	{
		Head = Tail = NewNode;
	}
	else
	{
		NewNode->Next = Head;
		NewNode->Prev = nullptr;
		Head->Prev = NewNode;
		Head = NewNode;
	}

	Length++;
	return *this;
    }

    DoublyLinkedList& PopBack()
    {
        Node<T>* Temp = Tail;
        Tail = Tail->Prev;
        Tail->Next = nullptr;

        delete Temp;

        Length--;
        return *this;
    }

    DoublyLinkedList& PopFront()
    {
        Node<T>* Temp = Head;
        Head = Head->Next;
        Head->Prev = nullptr;

        delete Temp;

        Length--;
        return *this;
    }

    T Back() const
    {
        return Tail->Data;
    }

    T Front() const
    {
        return Head->Data;
    }

    int Size() const
    {
        return Length;
    }

    void Print() const
    {
        Node<T>* Temp = Head;

        while (Temp)
        {
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
    }

private:
    Node<T>* Head;
    Node<T>* Tail;
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
    DoublyLinkedList<int> DL;
    DL.PushBack(10);
    DL.PushBack(20);
    DL.PushBack(30);
    DL.Print();
    cout << endl;

    DL.PushFront(100);
    DL.PushFront(200);
    DL.PushFront(300);
    DL.Print();
    cout << endl;

    DL.PopFront();
    DL.Print();
    cout << endl;

    DL.PopBack();
    DL.Print();
    cout << endl;

    cout << DL.Front() << " " << DL.Back() << endl;
}

}