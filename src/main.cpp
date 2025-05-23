#include "BinarySearchTree.h"
#include "Array.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"

int main()
{
    array_my::Array_Test();
    list_my::SinglyLinkedList_Test();
    list_my::DoublyLinkedList_Test();
    queue::Queue_Test();
    queue::Deque_Test();
    stack::Stack_Test();
    bst::BST_Test();
    hashtable::OpenAddressingHashTable_Test();

    return 0;
}