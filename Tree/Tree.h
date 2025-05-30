#include <iostream>
using namespace std;

namespace bst
{

template <typename T>
struct Node
{
	Node(T Data) : Data(Data), Left(nullptr), Right(nullptr) {}

	T Data;
	Node* Left;
	Node* Right;
};

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() : Root(nullptr), Height(0)
	{
	
	}
	
	BinarySearchTree& Insert(T Data)
	{
		Root = Insert(Root, Data);
		return *this;
	}

	BinarySearchTree& Remove(T Data)
	{
		Root = Remove(Root, Data);
		return *this;
	}

	bool Search(T Data)
	{
		return Search(Root, Data);
	}

	void Preorder()
	{
		Preorder(Root);
		std::cout << std::endl;
	}

	void Inorder()
	{
		Inorder(Root);
		std::cout << std::endl;
	}

	void Postorder()
	{
		Postorder(Root);
		std::cout << std::endl;
	}

private:
	Node<T>* Root;
	int Height;

	Node<T>* Insert(Node<T>* InNode, T Data)
	{
		if (InNode == nullptr) return new Node(Data);
		if (Search(InNode, Data)) return InNode;

		if (InNode->Data > Data)
		{
			InNode->Left = Insert(InNode->Left, Data);
		}
		else if (InNode->Data < Data)
		{
			InNode->Right = Insert(InNode->Right, Data);
		}

		return InNode;
	}

	Node<T>* Remove(Node<T>* InNode, T Data)
	{
		if (InNode == nullptr) return InNode;

		if (InNode->Data > Data)
		{
			InNode->Left = Remove(InNode->Left, Data);
		}
		else if (InNode->Data < Data)
		{
			InNode->Right = Remove(InNode->Right, Data);
		}
		else
		{
			if (InNode->Left == nullptr)
			{
				Node<T>* Temp = InNode->Right;
				delete InNode;
				return Temp;
			}
			else if (InNode->Right == nullptr)
			{
				Node<T>* Temp = InNode->Left;
				delete InNode;
				return Temp;
			}

			Node<T>* Temp = SearchCandidateNode(InNode->Right);
			InNode->Data = Temp->Data;
			InNode->Right = Remove(InNode->Right, Temp->Data);
		}

		return InNode;
	}

	Node<T>* SearchCandidateNode(Node<T>* InNode)
	{
		Node<T>* Current = InNode;
		while (Current && Current->Left != nullptr)
		{
			Current = Current->Left;
		}
		return Current;
	}

	bool Search(Node<T>* InNode, T Data)
	{
		if (InNode == nullptr) return false;
		if (InNode->Data == Data) return true;
		return (InNode->Data > Data) ? Search(InNode->Left, Data) : Search(InNode->Right, Data);
	}

	// 전위 순회 ( 부모 -> 왼쪽 자식 -> 오른쪽 자식 )
	void Preorder(Node<T>* InNode)
	{
		if (InNode != nullptr)
		{
			std::cout << InNode->Data << " ";
			Preorder(InNode->Left);
			Preorder(InNode->Right);
		}
	}

	// 중위 순회 ( 왼쪽 자식 -> 부모 -> 오른쪽 자식 )
	void Inorder(Node<T>* InNode)
	{
		if (InNode != nullptr)
		{
			Inorder(InNode->Left);
			std::cout << InNode->Data << " ";
			Inorder(InNode->Right);
		}
	}

	// 후위 순회 ( 왼쪽 자식 -> 오른쪽 자식 - > 부모 )
	void Postorder(Node<T>* InNode)
	{
		if (InNode != nullptr)
		{
			Postorder(InNode->Left);
			Postorder(InNode->Right);
			std::cout << InNode->Data << " ";
		}
	}
};

template <typename T>
using BST = BinarySearchTree<T>;

void BST_Test()
{
    cout << "------------- BST Test -------------" << '\n';
    BST<int> Tree;
	Tree.Insert(50);
	Tree.Insert(30);
	Tree.Insert(70);
	Tree.Insert(20);
	Tree.Insert(40);
	Tree.Insert(60);
	Tree.Insert(80);

	std::cout << "이진 탐색 트리 전위 순회 결과 : ";
	Tree.Preorder(); // 50 30 20 40 70 60 80

	std::cout << "이진 탐색 트리 중위 순회 결과 : ";
	Tree.Inorder(); // 20 30 40 50 60 70 80

	std::cout << "이진 탐색 트리 후위 순회 결과 : ";
	Tree.Postorder(); // 20 40 30 60 80 70 50

	std::cout << "검색 : 40 -> " << (Tree.Search(40) ? "발견" : "발견 못함") << std::endl;
	std::cout << "검색 : 90 -> " << (Tree.Search(90) ? "발견" : "발견 못함") << std::endl;
	Tree.Remove(70);

	std::cout << "이진 탐색 트리 70 삭제 후 전위 순회 결과 : ";
	Tree.Preorder(); // 5
}
}