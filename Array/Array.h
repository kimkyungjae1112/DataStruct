#include <iostream>
using namespace std;

namespace array_my
{

template<typename T>
class Array
{
public:
    Array(int a = 0) : Buffer(new T[a]), Length(a) {}

    void Insert(int Index, T Val)
    {
        Length++;
        T* Temp = new T[Length];
        for(int i = 0; i < Index; ++i)
        {
            Temp[i] = Buffer[i];
        }
        Temp[Index] = Val;
        for(int i = Index + 1; i < Length; ++i)
        {
            Temp[i] = Buffer[i - 1];
        }        
        delete[] Buffer;
        Buffer = Temp;
        Temp = nullptr;
    }

    void Erase(int Index)
    {
        Length--;
        T* Temp = new T[Length];
        for(int i = 0; i < Index; ++i)
        {
            Temp[i] = Buffer[i];
        }       
        
        for(int i = Index; i < Length; ++i)
        {
            Temp[i] = Buffer[i + 1];
        }  
        delete[] Buffer;
        Buffer = Temp;
        Temp = nullptr;
    }

    T& operator[](int Index)
    {
        if (Index < 0 || Index >= Length)
            throw out_of_range("Index out of bounds");
        return Buffer[Index];
    }

    int Size() const
    {
        return Length;
    }

private:
    T* Buffer;
    int Length;
};

void Array_Test()
{
    cout << "------------- Array Test -------------" << '\n';
    Array<int> array(10);
    
    for(int i = 0; i < array.Size(); ++i)
    {
        array[i] = i;
    }
    for(int i = 0; i < array.Size(); ++i)
    {
        cout << array[i] << endl;
    }
    array.Insert(4, 100);
    cout << "---" << endl;
    for(int i = 0; i < array.Size(); ++i)
    {
        cout << array[i] << endl;
    }
    array.Erase(4);
    cout << "---" << endl;
    for(int i = 0; i < array.Size(); ++i)
    {
        cout << array[i] << endl;
    }
}
}