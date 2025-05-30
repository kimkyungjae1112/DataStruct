#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
namespace hashtable
{

enum class SlotState
{
    Empty,
    Occupied,
    Deleted
};

template<typename K, typename V>
struct Entry
{
    K Key;
    V Value;
    SlotState State = SlotState::Empty;
};

template<typename K, typename V, typename Hash = std::hash<K>>
class OpenAddressingHashTable
{
public:
    OpenAddressingHashTable(int Size = DefaultSize) : Table(Size) { }

    void Insert(const K& Key, const V& Value)
    {
        int Index = GetIndex(Key);
        int OriginalIndex = Index;
        int FirstDeleted = -1;

        while (true)
        {
            auto& Slot = Table[Index];

            if (Slot.State == SlotState::Empty)
            {
                if (FirstDeleted != -1)
                {
                    Index = FirstDeleted;
                }
                Table[Index] = { Key, Value, SlotState::Occupied };
                Length++;
                return;
            }
            else if (Slot.State == SlotState::Deleted)
            {
                if (FirstDeleted == -1)
                {
                    FirstDeleted = Index;
                }
            }
            else if (Slot.State == SlotState::Occupied && Slot.Key == Key)
            {
                Slot.Value = Value;
                return;
            }

            Index = (Index + 1) % Table.size();
            if (Index == OriginalIndex)
            {
                break;
            }
        }

        cerr << "Hash Table Is Full!\n";
    }

    const V& Search(const K& Key)
    {
        int Index = GetIndex(Key);
        int OriginalIndex = Index;

        while (Table[Index].State != SlotState::Empty)
        {
            const auto& Slot = Table[Index];
            if (Slot.State == SlotState::Occupied && Slot.Key == Key)
            {
                return Slot.Value;
            }

            Index = (Index + 1) % Table.size();
            if (Index == OriginalIndex)
            {
                break; 
            }
        }

        throw std::out_of_range("Key not found in hash table");
    }

    bool Get(const K& Key, V& OutValue) const
    {
        int Index = GetIndex(Key);
        int OriginalIndex = Index;

        while (Table[Index].State != SlotState::Empty)
        {
            const auto& Slot = Table[Index];
            if (Slot.State == SlotState::Occupied && Slot.Key == Key)
            {
                OutValue = Slot.Value;
                return true;
            }

            Index = (Index + 1) % Table.size();
            if (Index == OriginalIndex)
            {
                break;
            }
        }

        return false;
    }

    bool Remove(const K& Key)
    {
        int Index = GetIndex(Key);
        int OriginalIndex = Index;

        while (Table[Index].State != SlotState::Empty)
        {
            auto& Slot = Table[Index];
            if (Slot.State == SlotState::Occupied && Slot.Key == Key)
            {
                Slot.State = SlotState::Deleted;
                Length--;
                return true;
            }

            Index = (Index + 1) % Table.size();
            if (Index == OriginalIndex)
            {
                break;
            }
        }

        return false;
    }

    int Size() const
    {
        return Length;
    }

    void Print() const
    {
        for (size_t I = 0; I < Table.size(); ++I)
        {
            const auto& Slot = Table[I];
            cout << "[" << I << "] ";
            if (Slot.State == SlotState::Empty)
            {
                cout << "Empty\n";
            }
            else if (Slot.State == SlotState::Deleted)
            {
                cout << "Deleted\n";
            }
            else
            {
                cout << "(" << Slot.Key << ", " << Slot.Value << ")\n";
            }
        }
    }

private:
    static const int DefaultSize = 10;
    vector<Entry<K, V>> Table;
    Hash Hasher;
    int Length = 0;

    int GetIndex(const K& Key) const
    {
        return Hasher(Key) % Table.size();
    }
};


void OpenAddressingHashTable_Test()
{
    cout << "------------- Open Addressing HashTable Test -------------\n";
    OpenAddressingHashTable<string, int> HT;

    HT.Insert("Apple", 100);
    HT.Insert("Banana", 200);
    HT.Insert("Orange", 300);
    HT.Insert("Apple", 123); 

    HT.Print();

    cout << "\n-- 바나나 삭제 --\n";
    HT.Remove("Banana");

    HT.Print();

    cout << "\n-- 포도 삭제 --\n";
    HT.Insert("Grape", 555); 

    HT.Print();

    int Value;
    if (HT.Get("Apple", Value))
    {
        cout << "\n[Get] Apple: " << Value << '\n';
    }

    cout << "Apple Value : " << HT.Search("Apple") << '\n';

}

}