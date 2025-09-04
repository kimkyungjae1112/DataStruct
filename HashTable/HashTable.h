#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
namespace hashtable
{

template<typename T>
struct FBucket
{
	string Key;
	T Data;
	bool bHasElement = false; 
};

template<typename T>
class HashTable
{
private:
	FBucket<T>* Buckets; 
	int Capacity;       
	int Size;           

	int Hash(const string& Key)
	{
		if (Capacity == 0)
		{
			return 0;
		}

		int Index = 0;
		for (char K : Key)
		{
			Index += K;
		}
		return Index % Capacity; 
	}

public:
	HashTable(int N) : Capacity(N), Size(0)
	{
		if (N <= 0)
		{
			Buckets = nullptr;
			Capacity = 0;
			return;
		}
		Buckets = new FBucket<T>[Capacity];
	}

	~HashTable()
	{
		delete[] Buckets;
	}

	HashTable(const HashTable&) = delete;
	HashTable& operator=(const HashTable&) = delete;


	void Add(const string& Key, T Value)
	{
		if (Capacity == 0)
		{
			cout << "Error: HashTable has zero capacity." << endl;
			return;
		}

		if (Size >= Capacity)
		{
			cout << "Error: HashTable is full." << endl;
			return;
		}

		int Index = Hash(Key);

		// 선형 탐사(Linear Probing): 충돌 발생 시 다음 칸으로 이동
		while (true)
		{
			// Case 1: 비어있는 버킷을 찾은 경우 (새로운 데이터 삽입)
			if (!Buckets[Index].bHasElement)
			{
				Buckets[Index].Key = Key;
				Buckets[Index].Data = Value;
				Buckets[Index].bHasElement = true;
				Size++;
				return;
			}
			// Case 2: 동일한 Key를 가진 버킷을 찾은 경우 (데이터 업데이트)
			else if (Buckets[Index].Key == Key)
			{
				Buckets[Index].Data = Value;
				return;
			}

			// 다음 인덱스로 이동 (배열 끝에 도달하면 처음으로 돌아감)
			Index = (Index + 1) % Capacity;
		}
	}

	bool Get(const string& Key, T& OutValue)
	{
		if (Capacity == 0)
		{
			return false;
		}

		int StartIndex = Hash(Key);
		int Index = StartIndex;

		while (true)
		{
			// Case 1: 비어있는 버킷을 만난 경우 -> 찾는 Key가 테이블에 없음
			if (!Buckets[Index].bHasElement)
			{
				return false;
			}
			// Case 2: 동일한 Key를 가진 버킷을 찾은 경우
			else if (Buckets[Index].Key == Key)
			{
				OutValue = Buckets[Index].Data; // 찾은 값을 OutValue에 복사
				return true;
			}

			// 다음 인덱스로 이동
			Index = (Index + 1) % Capacity;

			// 한 바퀴를 모두 돌았는데 못 찾은 경우 (테이블이 꽉 찼을 때)
			if (Index == StartIndex)
			{
				return false;
			}
		}
	}
};

void HashTableTest()
{
	cout << "HashTable(10) 생성" << endl;
	HashTable<int> HT(10);

	cout << "\n--- 데이터 추가 ---" << endl;
	HT.Add("Apple", 100);
	HT.Add("Orange", 200);
	HT.Add("Banana", 300);
	HT.Add("Grape", 400); 

	cout << "\n--- 데이터 조회 ---" << endl;
	int FoundValue;
	if (HT.Get("Apple", FoundValue))
	{
		cout << "Found Apple -> " << FoundValue << endl;
	}
	if (HT.Get("Grape", FoundValue))
	{
		cout << "Found Grape -> " << FoundValue << endl;
	}

	cout << "\n--- 데이터 업데이트 ---" << endl;
	cout << "Updating Apple's value to 150..." << endl;
	HT.Add("Apple", 150);
	if (HT.Get("Apple", FoundValue))
	{
		cout << "Found Apple -> " << FoundValue << endl;
	}

	cout << "\n--- 없는 데이터 조회 ---" << endl;
	if (HT.Get("Cherry", FoundValue))
	{
		cout << "Found Cherry -> " << FoundValue << endl;
	}
	else
	{
		cout << "Could not find Cherry." << endl;
	}
}

}